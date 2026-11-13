
#include <stdio.h>
#include <string.h>
#include <pigpio.h>

#define PIN 17
#define READING_COUNT 5
#define MIN_TEMP 68
#define MAX_TEMP 76

double average(int temperatures[], int count)
{
    int total_of_temps = 0;

    for (int i = 0; i < count; i++)
    {
        total_of_temps += temperatures[i];
    }

    return (double)total_of_temps / count;
}

int main()
{
    int temp[READING_COUNT];
    char SS[READING_COUNT][10];
    double average_result = 0;
    char WL[10] = "OFF";


    for (int i = 0; i < READING_COUNT; i++)
    {
        printf("Enter temperature reading %d in Fahrenheit: ", i + 1);
        scanf("%d", &temp[i]);
    }


    for (int i = 0; i < READING_COUNT; i++)
    {
        if (temp[i] < MIN_TEMP || temp[i] > MAX_TEMP)
        {
            strcpy(SS[i], "WARNING");
        }
        else
        {
            strcpy(SS[i], "NORMAL");
        }
    }

    average_result = average(temp, READING_COUNT);

    // Initialize Raspberry Pi GPIO
    if (gpioInitialise() < 0)
    {
        printf("GPIO initialization failed!\n");
        return 1;
    }

    gpioSetMode(PIN, PI_OUTPUT);


    if (average_result < MIN_TEMP || average_result > MAX_TEMP)
    {
        strcpy(WL, "ON");
        gpioWrite(PIN, 1);
    }
    else
    {
        strcpy(WL, "OFF");
        gpioWrite(PIN, 0);
    }


    printf("\nTEMPERATURE RESULTS\n");
    printf("----------------------------------\n");
    printf("Reading\tTemperature\tSystem Status\n");

    for (int i = 0; i < READING_COUNT; i++)
    {
        printf("%d\t%d F\t\t%s\n", i + 1, temp[i], SS[i]);
    }

    printf("----------------------------------\n");
    printf("Average Temperature: %.1f F\n", average_result);
    printf("Warning Light: %s\n", WL);


    gpioWrite(PIN, 0);
    gpioTerminate();

    return 0;
}

