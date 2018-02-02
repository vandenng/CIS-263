#include <iostream>
#include <cmath>

/********************************************************************************************
 * INFO for pow() found on the website cppreference.com
 *
 * This method will calculate the area of a circle for the given parameter radius.
 * *****************************************************************************************/

int calcArea(int radius){
	int area;
	area = pow(radius, 2);
	return area;
}

/********************************************************************************************
 *This Method will calculate the perimeter of the circle with the given radius by the
 *parmeter. The returned value will be returned in _PI format. This will simplify the
 *output for the users. 
 * *****************************************************************************************/
int clacPerimeter(int radius){
	int perimeter;
	perimeter = 2 * radius;
	return perimeter;
}

/********************************************************************************************
 * INFO for \u03C0 was obtained on the unicode character lookup for PI on fileformat.info 
 * INFO for cin.fail() was obtained at www.cpluplus.com.
 *
 * This main function will gerate the unser interface to enter the radius for
 * the given circle, and will display the area and perimeter of that circle with the
 * specified radius.
 *
 * Parameter int argc and char** argv are not used.
 * *****************************************************************************************/
int main(int argc, char** argv){
	int radius;

	std::cout << "Enter the radius of the circle here: " << std::endl;
	std::cin >> radius;

	if(std::cin.fail()){
		std::cout << "\n\nERROR: You must enter a whole numbered radius!\n\n" << std::endl;
		std::cin.clear();
		return 0;
	}

	if(radius < 0){
		std::cout << "\n\nERROR: You must enter a radius of a circle greater than 0!\n\n" << std::endl;
		return 0;
	}

	std::cout << "For the circle with radius " << radius << std::endl;
	std::cout << "Area = " << calcArea(radius) << "\u03C0" << std::endl;
	std::cout << "Perimeter = " << clacPerimeter(radius) << "\u03C0" << std::endl;

}

