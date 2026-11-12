#include <stdio.h>
#include <unistd.h>

#define PIN 17


int main()
{
    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;
    int temp4 = 0;
    int temp5 = 0; 
    char SS1[10] = "NORMAL"; //SS stands for System Status
    char SS2[10] = "NORMAL";
    char SS3[10] = "NORMAL";
    char SS4[10] = "NORMAL";
    char SS5[10] = "NORMAL";
    char WL1[10] = "OFF";
    char WL2[10] = "OFF";
    char WL3[10] = "OFF";
    char WL4[10] = "OFF";
    char WL5[10] = "OFF";


    int average(int temp1, int temp2, int temp3, int temp4, int temp5)
    {
        int total_of_temps = 0;
        int temp_average = 0;
        total_of_temps = temp1+temp2+temp3+temp4+temp5;
        temp_average = (total_of_temps)/5;

        return temp_average;
    }

    printf("Please enter first value: ");
    scanf("%d", &temp1);

    printf("Please enter second value: ");
    scanf("%d", &temp2);

    printf("Please enter third value: ");
    scanf("%d", &temp3);

    printf("Please enter fourth value: ");
    scanf("%d", &temp4);

    printf("Please enter fifth value: ");
    scanf("%d", &temp5);

    printf("==============================================\n");
    printf("TEMPERATURE   SYSTEM_STATUS   WARNING_LED\n");
    printf("   %d            %s               %s\n", temp1, SS1 ,WL1);
    printf("   %d            %s               %s\n", temp2, SS2, WL2);
    printf("   %d            %s               %s\n", temp3, SS3, WL3);
    printf("   %d            %s               %s\n", temp4, SS4, WL4);
    printf("   %d            %s               %s\n", temp5, SS5, WL5);
    int average_result = average(temp1, temp2, temp3, temp4, temp5);
    printf("TOTAL TEMP AVERAGE: %d\n", average_result);
    printf("==============================================\n");

  



}