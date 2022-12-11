/*
 * c_project.c
 *
 *  Created on: Apr 5, 2022
 *      Author: MohamedRagab
 */

#include <stdio.h>
#include <stdlib.h>
// enum for state ON/OFF
typedef enum{
	OFF = 0,
	ON = 1
}status;
//Structure for sensors measurements
typedef struct{
	int Engine;
	int AC;
	int vehicle_speed;
	int room_temprature;
	int engine_temp_controller;
	int engine_temprature;
}vehicle;
// variable of type vehicle
vehicle bmw = {ON,OFF,70,35,OFF,90};
// function for displaying main options
void Display_Main_Options(){
	printf("a. Turn on the vehicle engine\nb. Turn off the vehicle engine\nc. Quit the system\n");
}
// function for displaying sensors set menu
void Display_Sensors_Set_Menu(){
	printf("a. Turn off the engine\nb. Set the traffic light color.\nc. Set the room temperature (Temperature Sensor)\nd. Set the engine temperature (Engine Temperature Sensor)\n");
}
// function for displaying final sensors measurements value
void Display_Measurments(){
	if (bmw.Engine == OFF){
		printf("%s","Engine is OFF\n");
	}
	else{
		printf("%s","Engine is ON\n");
	}
	if (bmw.AC == OFF){
		printf("%s","AC is OFF\n");
	}
	else{
		printf("%s","AC is ON\n");
	}
	printf("Vehicle Speed: %d Km/Hr\nRoom Temperature: %d C\n",bmw.vehicle_speed,bmw.room_temprature);
	if (bmw.engine_temp_controller == OFF){
		printf("%s","Engine Temperature Controller is OFF\n");
	}
	else{
		printf("%s","Engine Temperature Controller is ON\n");
	}
	printf("Engine Temperature: %d C\n\n",bmw.engine_temprature);
}
//function to check whether vehicle speed is 30 or not
void Vehicle_Speed_Check(){
	if (bmw.vehicle_speed == 30){
		bmw.AC = ON;
	    bmw.room_temprature = bmw.room_temprature * 1.25 +1;
	    bmw.engine_temp_controller = ON;
	    bmw.engine_temprature = bmw.engine_temprature * 1.25 +1;
	}
}
//function for checking traffic light
void Traffic_light_Check(){
	char check_traffic_light;
	printf("%s","Enter the required color:\n");
	scanf(" %c",&check_traffic_light);
	switch(check_traffic_light){
	case 'G':
	case 'g':
		bmw.vehicle_speed = 100;
		break;
	case 'O':
	case 'o':
		bmw.vehicle_speed = 30;
		break;
	case 'R':
	case 'r':
		bmw.vehicle_speed = 0;
		break;
	}
	Vehicle_Speed_Check();
	Display_Measurments();
}
//function for checking room temperature
void Room_Temprature_Check(){
	printf("%s","Enter the required room temperature:\n");
	scanf("%d",&bmw.room_temprature);
	if (bmw.room_temprature<10){
		bmw.AC = ON;
		bmw.room_temprature = 20;
	}
	else if (bmw.room_temprature>30){
		bmw.AC = ON;
		bmw.room_temprature = 20;
	}
	else{
		bmw.AC = OFF;
	}
	Display_Measurments();
}
//function for checking engine temperature
void Engine_Temprature_Check(){
	printf("%s","Enter the required engine temperature:\n");
	scanf("%d",&bmw.engine_temprature);
	if (bmw.engine_temprature<100){
		bmw.engine_temp_controller = ON;
		bmw.engine_temprature = 125;
	}
	else if (bmw.engine_temprature>150){
		bmw.engine_temp_controller = ON;
		bmw.engine_temprature = 125;
	}
	else{
		bmw.engine_temp_controller = OFF;
	}
	Display_Measurments();
}
/* the upcoming two function Check_Main_Options and Check_Sensors_Menu are the core functions that contain all the previous functions
 * and manipulate them all */
// function to check main options
char Check_Main_Options(){
	char choose_option;
	scanf("%c",&choose_option);
	if(choose_option == 'c'){
		printf("%s","Quit the system");
	}
	else if (choose_option == 'b'){
		printf("%s","Turn off the vehicle engine\n\n");
		Display_Main_Options();
	}
	return choose_option;
}
//function to check sensors menu options
char Check_Sensors_Menu(){
	char check_sensors_menu;
	Display_Sensors_Set_Menu();
	scanf(" %c",&check_sensors_menu);
	switch(check_sensors_menu){
	case 'a':
		Display_Main_Options();
		break;
	case 'b':
		Traffic_light_Check();
		break;
	case 'c':
		Room_Temprature_Check();
		break;
	case 'd':
		Engine_Temprature_Check();
		break;
	}
	return check_sensors_menu;
}
int main(void){
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	// variables to store return values
	char main_options_checker;
	char sensors_menu_checker;
	// first display for the main options
	Display_Main_Options();
	// Application loop for doing the the two core function Check_Main_Options and Check_Sensors_Menu
	while(1)
	{
		// do while loop for Check_Main_Options function and the loop while not end until the user chooses 'a' or 'c'
		do{
			main_options_checker = Check_Main_Options();
		}while((main_options_checker!='a') && (main_options_checker != 'c'));
		// if the Check_Main_Options function returned 'c'  break the loop and quit the system
		if (main_options_checker == 'c'){
			break;
		}
		// if the user chooses 'a' the user will go to sensors menu and he will not return to the main option menu until he chooses option 'a' from sensors menu
		do{
			sensors_menu_checker = Check_Sensors_Menu();
		}while(sensors_menu_checker != 'a');
	}
	return 0;
}

