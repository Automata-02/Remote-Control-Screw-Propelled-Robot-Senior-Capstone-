
Arduino code for a differential screw propelled robot.
Project status: Completed

# Table of Contents
	* [What is this?](#what-is-this)
	* [Requirements](#requirements)
	* [Documentation](#documentation)
 	* [Circuit diagram](#circuit-diagram)
 	* [How to use](#how-to-use)
 	

# What is this?

This is an Arduino code repository for a senior capstone project.
This repository contains control code for a radio signal operated differential screw propelled robot.

![Senior_Capstone_Robot](https://github.com/user-attachments/assets/985de0dd-dd7b-4db2-8c33-4554179da3a7)


# Requirements
Hardware:
	
![Breadboard](https://github.com/user-attachments/assets/56048ae5-0013-4689-81e0-5894da09029c)
	
 	Breadboard

	
![Ardiuno_UNO_R3](https://github.com/user-attachments/assets/38bf10d0-282f-4b21-bcc5-ca4662f35030)
	
 	Arduino UNO R3

	
![sabertooth-dual-motor-driver-2x60](https://github.com/user-attachments/assets/5f982361-ae40-401e-bb0c-395d4b446ce8)
	
 	x2 Sabertooth 2x60 Motor Driver

	
![FS-R6B](https://github.com/user-attachments/assets/6162b76d-3ced-4bd5-b7e2-dc728a722814)
	
 	Flysky 2.4Ghz 6CH Receiver FS-R6B

	
![Flysky_FS-T4B_Controller](https://github.com/user-attachments/assets/78846e7e-d90b-4b25-b51e-ec44ed76673a)
	
 	Flysky FS-T4B Radio Control System

	
![NPC-T74_motor_Full_View](https://github.com/user-attachments/assets/e7f28302-7157-49df-9f1b-effe365766ba)
	
 	x4 NPC-T74 Motors

	
![BP7-12-Battery-L-01](https://github.com/user-attachments/assets/bc6a9c38-b1e8-424a-b984-0114de5c8163)
	
 	x2 12V 7Ah Battery

	
![Car_Power_Switch](https://github.com/user-attachments/assets/6a683eb7-a880-4c27-abb4-9aa802242677)
	
 	Main Switch/Safety Disconnect


	Libraries and other relevant software:
	Arduino IDE
	SoftwareSerial.h
	Sabertooth.h


# Circuit diagram

![Capstone_Electrical_Drawing](https://github.com/user-attachments/assets/bed44a00-397c-41af-8213-7c594f8cf8ab)


# How to use


The Arduino uses pins 2, 3, and 4 for radio signal inputs. Motor control instructions from the Arduino are output to pins 9, 10, 11, and 12.


The Sabretooth motor drivers have their pin configurations set to switch 1 UP, switch 2 UP, switch 3 DOWN, switch 4 DOWN, switch 5 DOWN, and switch 6 DOWN, putting the driver in analogue mode with mixing mode, exponential response, and 4x sensitivity activated.





