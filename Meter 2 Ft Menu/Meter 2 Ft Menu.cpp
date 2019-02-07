//Author: Dylan Hesser
//Date: 6/21/18
/* This program will allow a user to select an option from a menu that involves converting between English and Metric units. 
It will also allow a user to computer the volume of a rectangular solid in English, and translate it to metric. 
*/

#include <iostream>
using namespace std;
#include <cmath>
int choice;
char over ;
double measurement, meterMeasurement, feetMeasurement, length, width,height, area, volume;
const double ConvertLength = .3048 ; // This will stop the convert length from changing
//This function menu will display to the user and and ask them to choose one of the following options

void menu ( int ) 
{
   cout << "English-Metric Converter" << endl;
   cout << "   1) Convert from feet to meters" << endl;
   cout << "   2) Convert from meters to feet" << endl;
   cout << "   3) Compute area of a rectangle in square feet given length and width in meters" << endl;
   cout << "   4) Compute area of a rectangular solid in cubic meters given length, width, and height in feet" << endl;
   cout << "   5) Quit the Program" << endl;
   cout << "Please enter a number (1-5) ->";   
}
//These next two functions will convert from one measurement into the other
double feetToMeters ( double& testVariable )
{
   testVariable = testVariable * ConvertLength ;  
   return testVariable ;    
}

double metersToFeet ( double& testVariable2)
{
   testVariable2 = testVariable2 / ConvertLength ;
   return testVariable2 ;
}
//This function will translate the users input from meters to feet then calculate the area in feet
double areaInFeet (double& testVariable3, double& testVariable4)
{
   metersToFeet ( testVariable3 ) ;
   metersToFeet ( testVariable4 ) ;
   area = testVariable3 * testVariable4;
   return area;
}
//This function will translate the users input from feet to meters then calculate the volume in meters
double volumeInMeters (double& testVariable4, double& testVariable5, double& testVariable6)
{
   feetToMeters (testVariable4);
   feetToMeters (testVariable5);
   feetToMeters (testVariable6);
   volume = testVariable4 * testVariable5 * testVariable6;
}
   
int main ( ) 
{ 

   do
       {
         cout << "Hello, this program will allow you to convert between the English measuring units and the Metric measuring units \n " ;
    // This do while loop will make sure the user enters a valid option
          do 
              {  
                menu (choice);
                cin >> choice;
              }
          while ( ( choice < 1 ) || (choice > 5 ) ) ;
  //choice 1 will call the function to convert the user's response into meters
          if ( choice == 1 )
              {
                 cout << "You chose Converting from feet to meters " << endl;
                 cout << "Please insert the measurement in feet: " ;
                 cin >> feetMeasurement ;
                 feetToMeters ( feetMeasurement);
                 cout << "Here is your measurement in meters: " << feetMeasurement << endl;
              }
  //choice 2 will call the function to convert the user's response into feet 
          else if ( choice == 2 )
              {
                 cout << "You chose Converting from meters to feet " << endl;
                 cout << "Please insert the measurement in meters: " ;
                 cin >> meterMeasurement;
                 metersToFeet (meterMeasurement);
                 cout << "Here is your measurement in feet: " << meterMeasurement << endl;
              }
   //choice 3 is to use the area function
          else if ( choice == 3 )
              {
                 cout << "You chose to compute the area of a rectangle in square feet " << endl;
                 cout << "Please insert length in meters: " ;
                 cin >> length ;
                 cout << "Please insert width in meters: " ;
                 cin >> width ;
                 area = width * length;
                 cout << "This is your length in meters: " << length << endl;
                 cout << "This is your width in meters: " << width << endl;
                 cout << "This is the area in meters: " << area << endl;
                 areaInFeet (length, width);
                 cout << "This is the area in feet: " << area << endl;
              }
   //choice 4 will use the volume function
          else if ( choice == 4 ) 
              {
                 cout << "You chose to compute the volume of a rectangular solid in meters given feet" << endl;
                 cout << "Please insert the length of the rectangular solid: " ;
                 cin >> length ;
                 cout << "Please insert the width of the rectangular solid: " ;
                 cin >> width ;
                 cout << "Please insert the height of the rectangualr solid: " ;
                 cin >> height;
                 volume = length * width * height ;
                 cout << "This is your length in feet: " << length << endl;
                 cout << "This is your width in feet : " << width << endl;
                 cout << "This is your height in feet: " << height << endl;
                 cout << "This is your volume in feet: " << volume << endl;
                 volumeInMeters ( length, width, height ) ;
                 cout << "This is the volume of the rectangular solid in meters: " << volume << endl;
             }
   //choice 5 will quit the program
          else if ( choice == 5 ) 
              {
                 cout << "You chose to quit the program " << endl;
                 exit (0);
              }
        
          cout << "Would you like to start over or end? Type Y to end and any other letter to start over: " ;
          cin >> over;
      }
  while ( (over != 'y') && (over != 'Y') );
}