#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void main()
{
    int gd=DETECT,gm,k,tx,ty,deg;
    float sx,sy,rad, x1, x2, x3, x4, y1, y2, y3, y4;;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    printf("Enter coordinates of rectangle: ");
    scanf("%f%f%f%fl",&x1,&y1,&x2,&y2);
    rectangle(x1,y1,x2,y2);
    printf("1. Translation\n2. Scaling\n3. Rotation\nEnter your choice: ");
    scanf("%d",&k);
    switch(k)
    {
        case 1:
	    printf("Enter translation factors: ");
            scanf("%d%d",&tx,&ty);
            rectangle(x1,y1,x2,y2);
            x1+=tx;
            y1+=ty;
            x2+=tx;
            y2+=ty;
            rectangle(x1,y1,x2,y2);
            break;
        case 2:
	        printf("Enter scaling factors: ");
            scanf("%f%f",&sx,&sy);
            rectangle(x1,y1,x2,y2);
            x1=x1*sx;
            y1=y1*sy;
            x2=x2*sx;
            y2=y2*sy;
            rectangle(x1,y1,x2,y2);
            break;
        case 3:
		rad=deg * (3.14 / 180);
            x1 = x1 * cos(rad) - y2 * sin(rad);
            y1 = x1 * sin(rad) + y2 * cos(rad);
            x2 = x2 * cos(rad) - y2 * sin(rad);
            y2 = x2 * sin(rad) + y2 * cos(rad);
            x3 = x1 * cos(rad) - y1 * sin(rad);
            y3 = x1 * sin(rad) + y1 * cos(rad);
            x4 = x2 * cos(rad) - y1 * sin(rad);
            y4 = x2 * sin(rad) + y1 * cos(rad);
            line(fabs(x1), fabs(y1), fabs(x2), fabs(y2));
            line(fabs(x1), fabs(y1), fabs(x3), fabs(y3));
            line(fabs(x3), fabs(y3), fabs(x4), fabs(y4));
            line(fabs(x2), fabs(y2), fabs(x4), fabs(y4));
            break;
        default:
            printf("Invalid choice");
    }
    getch();
}