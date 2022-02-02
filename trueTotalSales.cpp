#include <iostream>
#include <iomanip>

using namespace std;

//GLobal Variables
int i = 0, j = 0;


//Declares And Defines getRowTotalSales
void getRowTotalSales (double sales[][3], double total[][3]){
	//Calculates the totals for the product from the three persons
	for(i = 0; i < 3; i++)
		total[0][i] = sales[0][i] + sales[1][i] + sales[2][i];
}

//Declares and Defines getColTotalSales
void getColTotalSales (double sales[][3], double total[][3]){
	//Calculates the totals for a person's sales
	for(i = 0; i < 3; i++){
		total[1][i] = sales[i][0] + sales[i][1] + sales[i][2];
	}
}

//Declares and Defines displayArray
void displayArray (double sales[][3], double total[][3]){
	//Table Headings
	cout << left << setw(10) << "Title" << setw(20) << "SalesPsn1" << setw(20) << "SalesPsn2" << setw(20) << "SalesPsn3" << "Total";
	cout << "\n--------------------------------------------------------------------------------------------\n";
	
	cout << fixed << setprecision(2) << showpoint;
	
	//Displays the sales and row headings
	for(i = 0; i < 3; i++){
		cout << setw(8) << "Product " << i + 1 << setw(2) << " ";
		
		for(j = 0; j < 3; j++)
		cout << setw(20) << sales[j][i];
		
		cout << setw(20) << total[0][i];
		
		cout << endl;
	}
	
	cout << setw(11) << "Total";
	
	for( i = 0; i < 3; i++)
		cout << setw(20) << total[1][i];
	
	cout << "\n--------------------------------------------------------------------------------------------\n";
}

int main (){
	//Declares Arrays
	double sales[3][3] = {250,500,150,200,350,600,300,220,450}, total[2][3] = {0};
	
	//Calls Functions
	getRowTotalSales (sales, total);
	getColTotalSales (sales, total);
	displayArray (sales, total);
	
	//Ends Program
	return 0;
}
