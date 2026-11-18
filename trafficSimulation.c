#include <graphics.h>
#include <conio.h>
#include <dos.h>

// Function to draw traffic signal
void signal(int color)
{
    setcolor(WHITE);

    rectangle(500, 50, 580, 280);
    line(540, 280, 540, 450);

    // Red light
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(540, 90, 25, 25);

    // Yellow light
    fillellipse(540, 160, 25, 25);

    // Green light
    fillellipse(540, 240, 25, 25);

    // ON light
    setfillstyle(SOLID_FILL, color);

    if(color == RED)
        fillellipse(540, 90, 25, 25);

    else if(color == YELLOW)
        fillellipse(540, 160, 25, 25);

    else
        fillellipse(540, 240, 25, 25);
}

// Function to draw car
void car(int x)
{
    // Car body
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, BLUE);
    bar(x, 300, x + 130, 345);

    // Car roof
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(x + 30, 270, x + 100, 300);

    // Car windows
    setcolor(WHITE);
    rectangle(x + 35, 275, x + 60, 295);
    rectangle(x + 65, 275, x + 95, 295);

    // Wheels
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(x + 30, 345, 15, 15);
    fillellipse(x + 100, 345, 15, 15);

    // Wheel centers
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(x + 30, 345, 6, 6);
    fillellipse(x + 100, 345, 6, 6);
}

// Main program
int main()
{
    int gd = DETECT, gm;
    int x, i, vehicle;

    initgraph(&gd, &gm, "");

    while(!kbhit())
    {
        for(vehicle = 1; vehicle <= 3; vehicle++)
        {
            // Draw road
            cleardevice();

            setcolor(WHITE);
            line(0, 370, 640, 370);
            line(0, 430, 640, 430);

            // Road divider
            for(i = 0; i < 640; i += 80)
                line(i, 400, i + 40, 400);

            // Vehicle number
            setcolor(WHITE);
            outtextxy(20, 30, "TRAFFIC SIMULATION");

            // RED LIGHT - CAR STOP
            signal(RED);

            car(340);

            outtextxy(20, 60, "RED LIGHT - STOP");

            delay(2000);

            // YELLOW LIGHT - ONCE
            cleardevice();

            line(0, 370, 640, 370);
            line(0, 430, 640, 430);

            for(i = 0; i < 640; i += 80)
                line(i, 400, i + 40, 400);

            signal(YELLOW);
            car(340);

            outtextxy(20, 60, "YELLOW LIGHT - WAIT");

            delay(1000);

            // GREEN LIGHT - CAR MOVES
            for(x = 340; x < 650 && !kbhit(); x += 10)
            {
                cleardevice();

                line(0, 370, 640, 370);
                line(0, 430, 640, 430);

                for(i = 0; i < 640; i += 80)
                    line(i, 400, i + 40, 400);

                signal(GREEN);

                car(x);

                outtextxy(20, 60, "GREEN LIGHT - GO");

                delay(100);
            }

            // Next vehicle comes
            // Signal will become RED again
        }
    }

    closegraph();
    return 0;
}