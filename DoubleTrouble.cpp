#include <GL/glut.h>///#include <glut.h>
#include <stdio.h>
#include <GL/gl.h>///#include <glut.h>
#include <GL/glu.h>///#include <glut.h>
#include<ctime>
#define FROM_RIGHT      1 
#define FROM_LEFT       2 
#define FROM_TOP        3 
#define FROM_BOTTOM     4 
 
static int WINDOW_WIDTH ,WINDOW_HEIGHT;

int playerResult=0;
static float Xspeed=0.5,Yspeed=0.5; 
static float delta=0.5; 

char string [100];

struct RECTA
{ 
        float left,top,right,bottom; 
};

RECTA ball={100,100,120,120};
RECTA ball2={200,300,220,320};
RECTA wall ;
RECTA player_1 ={0,490,40,500},player_2={0,0,45,20}; 
 RECTA temp;
void DrawRectangle(RECTA  rect) 
{         glColor3f(1.0,1.0,0.0);
        glBegin(GL_QUADS); 
        glVertex2f(rect.left,rect.bottom);      //Left - Bottom 
        glVertex2f(rect.right,rect.bottom); 
        glVertex2f(rect.right,rect.top); 
        glVertex2f(rect.left,rect.top); 
        glEnd(); 
}
void DrawRectangle2(RECTA  rect) 
{        glColor3f(1.0,1.0,1.0);
        glBegin(GL_QUADS); 
        glVertex2f(rect.left,rect.bottom);      //Left - Bottom 
        glVertex2f(rect.right,rect.bottom); 
        glVertex2f(rect.right,rect.top); 
        glVertex2f(rect.left,rect.top); 
        glEnd(); 
       
}
void DrawRectangle3(RECTA  rect) 
{        glColor3f(0.0,0.0,0.0);
        glBegin(GL_QUADS); 
        glVertex2f(rect.left,rect.bottom);      //Left - Bottom 
        glVertex2f(rect.right,rect.bottom); 
        glVertex2f(rect.right,rect.top); 
        glVertex2f(rect.left,rect.top); 
        glEnd(); 
       
}
void DrawRectangle4() 
{        glColor3f(0.0,0.0,0.0);
        glBegin(GL_QUADS); 
        glVertex2f(0,20);      //Left - Bottom 
        glVertex2f(0,0); 
        glVertex2f(795,0); 
        glVertex2f(795,20); 
        glEnd(); 
       
}
/*void DrawRectangle1(RECTA  rect) 
{    
     
        glBegin(GL_QUADS);
      if(rect.right<=810)
      { 
        glVertex2f(rect.left,rect.bottom);       
        glVertex2f(rect.right,rect.bottom); 
        glVertex2f(rect.right,rect.top); 
        glVertex2f(rect.left,rect.top);
        temp=rect;
      }
    else
     {
       glVertex2f(temp.left,temp.bottom);     
        glVertex2f(temp.right,temp.bottom); 
        glVertex2f(temp.right,temp.top); 
        glVertex2f(temp.left,temp.top);

      }
        glEnd(); 
}*/

void Timer(int v) 
{ 
        
 
        ball.left+=Xspeed; 
        ball.right+=Xspeed; 
        ball.top+=Yspeed; 
        ball.bottom+=Yspeed; 
        ball2.left+=Xspeed; 
        ball2.right+=Xspeed; 
        ball2.top+=Yspeed; 
        ball2.bottom+=Yspeed; 
 
        glutTimerFunc(1,Timer,1);
}
void drawText(char*string,int x,int y)
{
	  char *c;
	  glPushMatrix();
	  glTranslatef(x, y,0);
	  glScalef(0.1,-0.1,1);
  
	  for (c=string; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	  }
	  glPopMatrix();

}
 
int Test_Ball_Wall(RECTA  ball , RECTA wall) 
{ 
        if(ball.right >=wall.right) 
        return FROM_RIGHT;  
        if(ball.left <=wall.left) 
        return FROM_LEFT;  
        if(ball.top <=wall.top) 
       return FROM_TOP;  
      //  if(ball.bottom ==wall.bottom) 
        //return FROM_BOTTOM;  
 
        //else return 0 ; 
}
int Test_Ball_Wall2(RECTA  ball , RECTA wall) 
{ 
        if(ball.right >=wall.right) 
        return FROM_RIGHT;  
        if(ball.left <=wall.left) 
        return FROM_LEFT;  
       // if(ball.top <=wall.top) 
        //return FROM_TOP;  
      if(ball.bottom ==wall.bottom) 
       return FROM_BOTTOM;  
 
        //else return 0 ; 
}

/*bool Test_Ball_Player(RECTA ball,RECTA player) 
{ 
       
		if(ball.bottom <= player.top  ) 
        {
			if((ball.bottom == player.top) &&(ball.left<=player.right&&ball.right>=player.left))
                         playerResult++;
		
            return true;  
		}
      else
            return false;  
}*/
 
// Key Board Messages 
void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
   }
}

//Key Board Message 
void inputKey(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_LEFT : 

			break;

		case GLUT_KEY_RIGHT : 

			break;


		case GLUT_KEY_UP : 

			break ;


		case GLUT_KEY_DOWN : 

			break;


	}
}



static int  mouse_x=0; 
void MouseMotion(int x,int y)
{
 
	mouse_x=x;
}


// OpenGL Setting
void Setting(void) 
{
   glClearColor (0.2, 0.2,0.45, 0.0);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

 
// OnWindowResize 
void reshape (int w, int h)
{
	WINDOW_WIDTH =w ;
	WINDOW_HEIGHT =h ;

   glViewport (0, 0, (GLsizei) w, (GLsizei) h);

   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluOrtho2D (0, w, h, 0);


   glMatrixMode (GL_MODELVIEW);
   glLoadIdentity ();

}


void Render()
{
	glClear(GL_COLOR_BUFFER_BIT );
	glLoadIdentity();
	sprintf(string,"Player_score : %d ",playerResult);
	drawText(string,10,120);

	wall.left=0;
         wall.top=20;
	wall.right=WINDOW_WIDTH;
	wall.bottom=WINDOW_HEIGHT;

	DrawRectangle(ball);
         DrawRectangle3(player_1);
         DrawRectangle4();
       DrawRectangle2(player_2);
       DrawRectangle(ball2); 

	if(Test_Ball_Wall(ball,wall)== FROM_RIGHT) 
    Xspeed=-delta; 
         
    if(Test_Ball_Wall(ball,wall)== FROM_LEFT) 
    Xspeed=delta; 

    if(Test_Ball_Wall(ball,wall)== FROM_TOP) 
    Yspeed=delta; 
        if(Test_Ball_Wall2(ball2,wall)== FROM_RIGHT) 
    Xspeed=-delta; 
         
    if(Test_Ball_Wall2(ball2,wall)== FROM_LEFT) 
    Xspeed=delta; 

    if(Test_Ball_Wall2(ball2,wall)== FROM_BOTTOM) 
    Yspeed=-delta; 
   
    player_1.left=mouse_x-65; 
    player_1.right=mouse_x+65; 
    player_2.left=mouse_x-100; 
    player_2.right=mouse_x+100; 
       
		if(ball.bottom <= player_1.top && ball.bottom <= player_1.top ) 
        {
			if((ball.bottom == player_1.top) &&(ball.left<=player_1.right && ball.right>=player_1.left))
                        { playerResult++;Yspeed=-delta; }
                        if((ball2.bottom == player_1.top) &&(ball2.left<=player_1.right && ball2.right>=player_1.left))
                        { playerResult++;Yspeed=-delta; }
        
		}
             if(ball.top >= player_2.bottom && ball2.top >=player_2.bottom ) 
        {
			if((ball2.top == player_2.bottom) &&(ball2.left<=player_2.right && ball2.right>=player_2.left))
                        { playerResult++;Yspeed=-delta; }
                        if((ball.top == player_2.bottom) &&(ball.left<=player_2.right && ball.right>=player_2.left))
                        { playerResult++;Yspeed=-delta; }
        
		}
 
    
      if(ball.bottom > player_1.top || ball2.bottom>player_1.top ||ball.top < player_2.bottom || ball2.top < player_2.bottom) 
         { 
	   
	
            
                exit(0); 
           }

	glutSwapBuffers();
}


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (795, 500); 
   glutInitWindowPosition (0, 0);
   glutCreateWindow ("16-1-5-013&014 OpenGL game||enter esc to end the game");


    Setting ();



   glutDisplayFunc(Render); 
   glutIdleFunc(Render);

   glutTimerFunc(1,Timer,1);

   glutReshapeFunc(reshape);
   
   glutKeyboardFunc(keyboard);

   glutSpecialFunc(inputKey);
   //glutSpecialUpFunc(upkey);

   glutPassiveMotionFunc(MouseMotion);


   glutMainLoop();
    
   return 0;
}
