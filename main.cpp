void DrawAlienBody(bool isPlayer1)
{
	if(isPlayer1)
		glColor3f(0,1,0);
	else
		glColor3f(1,1,0);		//BODY color
	glBegin(GL_POLYGON);
	for(int i=0;i<=8;i++)
		glVertex2fv(AlienBody[i]);
	glEnd();

	glColor3f(0,0,0);			//BODY Outline
	glLineWidth(1);
	glBegin(GL_LINE_STRIP);
	for(int i=0;i<=8;i++)
		glVertex2fv(AlienBody[i]);
	glEnd();

	glBegin(GL_LINES);                //BODY effect
		glVertex2f(-13,11);
		glVertex2f(-15,9);
	glEnd();
}
void DrawAlienCollar()
{
	glColor3f(1,0,0);				//COLLAR
	glBegin(GL_POLYGON);
	for(int i=0;i<=20 ;i++)
		glVertex2fv(AlienCollar[i]);
	glEnd();

	glColor3f(0,0,0);				//COLLAR outline
	glBegin(GL_LINE_STRIP);
	for(int i=0;i<=20 ;i++)
		glVertex2fv(AlienCollar[i]);
	glEnd();
}
void DrawAlienFace(bool isPlayer1)
{
	//glColor3f(0.6,0.0,0.286);				//FACE
	//glColor3f(0.8,0.2,0.1);
	//glColor3f(0,0.5,1);
	//if(isPlayer1)
	glColor3f(0,0,1);
	// else
	// 	glColor3f(0,1,0);

	glBegin(GL_POLYGON);
	for(int i=0;i<=42 ;i++)
		glVertex2fv(ALienFace[i]);
	glEnd();

	glColor3f(0,0,0);				//FACE outline
	glBegin(GL_LINE_STRIP);
	for(int i=0;i<=42 ;i++)
		glVertex2fv(ALienFace[i]);
	glEnd();

	glBegin(GL_LINE_STRIP);      //EAR effect
		glVertex2f(3.3,22);
		glVertex2f(4.4,23.5);
		glVertex2f(6.3,26);
	glEnd();
}
void DrawAlienBeak()
{
	glColor3f(1,1,0);				//BEAK color
	glBegin(GL_POLYGON);
	for(int i=0;i<=14 ;i++)
		glVertex2fv(ALienBeak[i]);
	glEnd();

	glColor3f(0,0,0);				//BEAK outline
	glBegin(GL_LINE_STRIP);
	for(int i=0;i<=14 ;i++)
		glVertex2fv(ALienBeak[i]);
	glEnd();
}
void DrawAlienEyes(bool isPlayer1)
{
	// if(isPlayer1)
	glColor3f(0,1,1);
	// else
	// 	glColor3f(0,0,0);

	glPushMatrix();
	glRotated(-10,0,0,1);
	glTranslated(-6,32.5,0);      //Left eye
	glScalef(2.5,4,0);
	glutSolidSphere(1,20,30);
	glPopMatrix();

	glPushMatrix();
	glRotated(-1,0,0,1);
	glTranslated(-8,36,0);							//Right eye
	glScalef(2.5,4,0);
	glutSolidSphere(1,100,100);
	glPopMatrix();
}

void DrawAlien(bool isPlayer1)
{
	DrawAlienBody(isPlayer1);
	DrawAlienCollar();
	DrawAlienFace(isPlayer1);
	DrawAlienBeak();
	DrawAlienEyes(isPlayer1);
}
void DrawSpaceshipBody(bool isPlayer1)
{
	if(isPlayer1)
		glColor3f(1, 0, 0);			//BASE
	else
		glColor3f(0.5, 0, 0.5);

	glPushMatrix();
	glScalef(70,20,1);
	glutSolidSphere(1,50,50);
	glPopMatrix();

	glPushMatrix();							//LIGHTS
	glScalef(3,3,1);
	glTranslated(-20,0,0);			//1
	glColor3fv(LightColor[(CI+0)%3]);
	glutSolidSphere(1,1000,1000);
	glTranslated(5,0,0);					//2
	glColor3fv(LightColor[(CI+1)%3]);
	glutSolidSphere(1,1000,1000);
	glTranslated(5,0,0);					//3
	glColor3fv(LightColor[(CI+2)%3]);
	glutSolidSphere(1,1000,1000);
	glTranslated(5,0,0);					//4
	glColor3fv(LightColor[(CI+0)%3]);
	glutSolidSphere(1,1000,1000);
	glTranslated(5,0,0);					//5
	glColor3fv(LightColor[(CI+1)%3]);
	glutSolidSphere(1,1000,1000);
	glTranslated(5,0,0);					//6
	glColor3fv(LightColor[(CI+2)%3]);
	glutSolidSphere(1,1000,1000);
	glTranslated(5,0,0);					//7
	glColor3fv(LightColor[(CI+0)%3]);
	glutSolidSphere(1,1000,1000);
	glTranslated(5,0,0);					//8
	glColor3fv(LightColor[(CI+1)%3]);
	glutSolidSphere(1,1000,1000);
	glTranslated(5,0,0);					//9
	glColor3fv(LightColor[(CI+2)%3]);
	glutSolidSphere(1,1000,1000);

	glPopMatrix();
}
void DrawSteeringWheel()
{
	glPushMatrix();
	glLineWidth(3);
	glColor3f(0.20,0.,0.20);
	glScalef(7,4,1);
	glTranslated(-1.9,5.5,0);
	glutWireSphere(1,8,8);
	glPopMatrix();

}
void DrawSpaceshipDoom()
{
	glColor4f(0.7,1,1,0.0011);
	glPushMatrix();
	glTranslated(0,30,0);
	glScalef(35,50,1);
	glutSolidSphere(1,50,50);
	glPopMatrix();
}

void DrawLaser(int x, int y, bool dir[]) {
	//glPushMatrix();
	int xend = -XMAX, yend = y;
	if(dir[0])
		yend = YMAX;
	else if(dir[1])
		yend = -YMAX;
	glLineWidth(5);
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
		glVertex2f(x, y);
		glVertex2f(xend, yend);
	glEnd();
	//glPopMatrix();
}

void SpaceshipCreate(int x, int y, bool isPlayer1){
	glPushMatrix();
	glTranslated(x,y,0);
	// if(!checkIfSpaceShipIsSafe() && alienLife1 ){
	// 	alienLife1-=10;
	// 	xStart -= 23;
	// }
	DrawSpaceshipDoom();
	glPushMatrix();
	glTranslated(4,19,0);
	DrawAlien(isPlayer1);
	glPopMatrix();
	DrawSteeringWheel();
	DrawSpaceshipBody(isPlayer1);
	// DrawSpaceShipLazer();
	// if(mButtonPressed) {
	// 	DrawLazerBeam();
	// }
	glEnd();
	glPopMatrix();
}

void DisplayHealthBar1() {
	char temp1[40];
	glColor3f(1 ,1 ,1);
	sprintf(temp1,"  LIFE = %d",alienLife1);
	displayRasterText(-1100 ,600 ,0.4 ,temp1);
	glColor3f(1 ,0 ,0);
}

void DisplayHealthBar2() {
	char temp2[40];
	glColor3f(1 ,1 ,1);
	sprintf(temp2,"  LIFE = %d",alienLife2);
	displayRasterText(800 ,600 ,0.4 ,temp2);
	glColor3f(1 ,0 ,0);
}

void checkLaserContact(int x, int y, bool dir[], int xp, int yp, bool player1) {
	int xend = -XMAX, yend = y;
	xp += 8; yp += 8; // moving circle slightly up to fix laser issue
	if(dir[0])
		yend = YMAX;
	else if(dir[1])
		yend = -YMAX;

	// Here we find out if the laser(line) intersects with spaceship(circle)
	// by solving the equations for the same and finding the discriminant of the
	// quadratic equation obtained
	float m = (float)(yend - y) / (float)(xend - x);
	float k = y - m * x ;
	int r = 50; // approx radius of the spaceship

	//calculating value of b, a, and c needed to find discriminant
	float b = 2 * xp - 2 * m * (k - yp);
	float a = 1 + m * m;
	float c = xp * xp + (k - yp) * (k - yp) - r * r;

	float d = (b * b - 4 * a * c); // discriminant for the equation
	printf("\nDisc: %f x: %d, y: %d, xp: %d, yp: %d", d, x, y, xp, yp);
	if(d >= 0) {
		if(player1)
			alienLife1 -= 5;
		else
			alienLife2 -= 5;

		printf("%d %d\n", alienLife1, alienLife2);
	}
}

void gameScreenDisplay()
{
	DisplayHealthBar1();
	DisplayHealthBar2();
	glScalef(2, 2 ,0);

	if(alienLife1 > 0){
		SpaceshipCreate(xOne, yOne, true);
		if(laser1) {
			DrawLaser(xOne, yOne, laser1Dir);
			checkLaserContact(xOne, yOne, laser1Dir, -xTwo, yTwo, true);
		}
	}
	else {
		viewPage = GAMEOVER;
	}

	if(alienLife2 > 0) {
		glPushMatrix();
		glScalef(-1, 1, 1);
		SpaceshipCreate(xTwo, yTwo, false);
		if(laser2) {
			DrawLaser(xTwo, yTwo, laser2Dir);
			checkLaserContact(xTwo, yTwo, laser2Dir, -xOne, yOne, false);
		}
		glPopMatrix();
	}
	else {
		viewPage = GAMEOVER;
	}

	if(viewPage == GAMEOVER) {
		xOne = xTwo = 500;
		yOne = yTwo = 0;
	}
}

void displayGameOverMessage() {
	glColor3f(1, 1, 0);
	char* message;
	if(alienLife1 > 0)
		message = "Game Over! Player 1 won the game";
	else
		message = "Game Over! Player 2 won the game";

	displayRasterText(-350 ,600 ,0.4 , message);
}

void keyOperations() {
	if(keyStates[13] == true && viewPage == INTRO) {
		viewPage = MENU;
		printf("view value changed to %d", viewPage);
		printf("enter key pressed\n");
	}
	if(viewPage == GAME) {
		laser1Dir[0] = laser1Dir[1] = false;
		laser2Dir[0] = laser2Dir[1] = false;
		if(keyStates['c'] == true) {
			laser2 = true;
			if(keyStates['w'] == true) 	laser2Dir[0] = true;
			if(keyStates['s'] == true) 	laser2Dir[1] = true;
		}
		else {
			laser2 = false;
			if(keyStates['d'] == true) xTwo-=SPACESHIP_SPEED;
			if(keyStates['a'] == true) xTwo+=SPACESHIP_SPEED;
			if(keyStates['w'] == true) yTwo+=SPACESHIP_SPEED;
			if(keyStates['s'] == true) yTwo-=SPACESHIP_SPEED;
		}

		if(keyStates['m'] == true) {
			laser1 = true;
			if(keyStates['i'] == true) laser1Dir[0] = true;
			if(keyStates['k'] == true) laser1Dir[1] = true;
		}
		else {
			laser1 = false;
			if(keyStates['l'] == true) xOne+=SPACESHIP_SPEED;
			if(keyStates['j'] == true) xOne-=SPACESHIP_SPEED;
			if(keyStates['i'] == true) yOne+=SPACESHIP_SPEED;
			if(keyStates['k'] == true) yOne-=SPACESHIP_SPEED;
		}
	}
}

void display()
{
	//glClearColor(, 0 , 0, 1);
	keyOperations();
	glClear(GL_COLOR_BUFFER_BIT);

	switch (viewPage)
	{
		case INTRO:
			introScreen();
			break;
		case MENU:
			startScreenDisplay();
			break;
		case INSTRUCTIONS:
			instructionsScreenDisplay();
			break;
		case GAME:
			gameScreenDisplay();
			//reset scaling values
			glScalef(1/2 ,1/2 ,0);
			break;
		case GAMEOVER:
			displayGameOverMessage();
			startScreenDisplay();
			break;
	}

	glFlush();
	glLoadIdentity();
	glutSwapBuffers();
}

// void reshape(GLint w, GLint h)
// {
// 	glViewport(0, 0, w, h);
// 	glMatrixMode(GL_PROJECTION);
// 	glLoadIdentity();
// 	if(h>w)
// 	{
// 		gluOrtho2D(0, 500, ((float)h/(float)w)*(0), ((float)h/(float)w)*500);
// 	}
// 	else
// 	{
// 		gluOrtho2D(((float)w/(float)h)*(0), ((float)w/(float)h)*(500), 0, 500);
// 	}
// 	glMatrixMode(GL_MODELVIEW);
// 	glutPostRedisplay();
// }

void passiveMotionFunc(int x,int y) {

	//when mouse not clicked
	mouseX = float(x)/(m_viewport[2]/1200.0)-600.0;  //converting screen resolution to ortho 2d spec
	mouseY = -(float(y)/(m_viewport[3]/700.0)-350.0);

	//Do calculations to find value of LaserAngle
	//somethingMovedRecalculateLaserAngle();
	glutPostRedisplay();
}

void mouseClick(int buttonPressed ,int state ,int x, int y) {

	if(buttonPressed == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		mButtonPressed = true;
	else
		mButtonPressed = false;
	glutPostRedisplay();
}

void keyPressed(unsigned char key, int x, int y)
{
	keyStates[key] = true;
	glutPostRedisplay();
}

void refresh() {
	glutPostRedisplay();
}

void keyReleased(unsigned char key, int x, int y) {
	keyStates[key] = false;
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1200, 600);
    glutCreateWindow("Space Shooter");
    init();
    //glutReshapeFunc(reshape);
	glutIdleFunc(refresh);
    glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyReleased);
	glutMouseFunc(mouseClick);
	glutPassiveMotionFunc(passiveMotionFunc);
	glGetIntegerv(GL_VIEWPORT ,m_viewport);
    glutDisplayFunc(display);
    glutMainLoop();
}
