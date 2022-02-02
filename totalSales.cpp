#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//GLobal Variables
int i = 0, j = 0;


//Declares And Defines getRowTotalSales
void getInputs (double sales[][3], string product[], string name[]){
	//Prompt for the sales persons
	for(i = 0; i < 3; i++){
		cout << "Enter the name of Sales Person " << i + 1 << ": ";
		cin >> name[i];
	}
	
	cout << endl;
	
	//Prompts for the products being used
	for(i = 0; i < 3; i++){
		cout << "Enter the name of product " << i + 1 << ": ";
		cin >> product[i];
	}
	
	cout << endl;
	
	//Prompts for the sales earned for a product by a person
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			cout << "Enter the sales for the " << product[j] << " earned by " << name[i] << ": $";
			cin >> sales[i][j];
		}
		cout << endl;
	}
}

//Declares and Defines rowCalTotalSales
void calTotalSales (double sales[][3], double total[][3]){
	//Calculates the totals for the product from the three persons
	for(i = 0; i < 3; i++)
		total[0][i] = sales[0][i] + sales[1][i] + sales[2][i];
	
	//Calculates the totals for a person's sales
	for(i = 0; i < 3; i++){
		total[1][i] = sales[i][0] + sales[i][1] + sales[i][2];
	}
}

//Declares and Defines displayArray
void displayArray (double sales[][3], double total[][3], string product[], string name[]){
	//Table Headings
	cout << left << setw(10) << "Title" << setw(20) << name[0] + "'s Sales" << setw(20) << name[1] + "'s Sales" << setw(25) << name[2] + "'s Sales" << "Total";
	cout << "\n--------------------------------------------------------------------------------------------\n";
	
	cout << fixed << setprecision(2) << showpoint;
	
	//Displays the sales and row headings
	for(i = 0; i < 3; i++){
		cout << setw(10) << product[i];
		
		for(j = 0; j < 3; j++)
		cout << setw(22) << sales[j][i];
		
		cout << setw(22) << total[0][i];
		
		cout << endl;
	}
	
	cout << setw(10) << "Total";
	
	for( i = 0; i < 3; i++)
		cout << setw(22) << total[1][i];
	
	cout << "\n--------------------------------------------------------------------------------------------\n";
}

int main (){
	//Declares Arrays
	double sales[3][3] = {0}, total[2][3] = {0};
	string product[3] = {""}, name[3] = {""};
	
	//Welcome Message
	cout << "Welcome To The Sales Calculator" << endl;
	
	//Calls Functions
	getInputs (sales, product, name);
	calTotalSales (sales, total);
	displayArray (sales, total, product, name);
	
	//Ends Program
	return 0;
}

