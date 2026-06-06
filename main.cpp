#include<iostream>
using namespace std;

//function prototypes

double inputValidation(double score); //function to validate input for test scores (0-100)

void InputTestScores(double* arr, int* sizeptr); //function to input test scores

void SortTestScores(double* arr, int* sizeptr); //function to sort test scores in ascending order

void AverageofTestScores(double* arr, int* sizeptr, double* averageptr); //function to calculate avg

void DisplayTestScores(double* arr, int* sizeptr); //function to display sorted scores

int main()
{
	//avg and size variables with pointers
	double average = 0.0;
	double* averageptr = &average;
    int size = 0;
	int* sizeptr = &size;

	//input validation for size of test scores
	while (true)
	{
		cout << "Enter The Number of Test Scores: ";
		cin >> *sizeptr;
		if (*sizeptr > 0) //if size is greater than 0, break the loop
		{
			break;
		}
		else //if size less than or equal to 0,ask again for input 
		{
			cout << "Number of Test Scores Must Be Greater Than 0" << endl;
		}
	}

	double* arr = new double[*sizeptr]; //dynamically allocate array for test scores

	//function calls
	InputTestScores(arr, sizeptr); //function call to input test scores

	SortTestScores(arr, sizeptr); //function call to sort test scores in ascending order

	AverageofTestScores(arr, sizeptr, averageptr); //function call to calculate average of test scores

	DisplayTestScores(arr, sizeptr); //function call to display sorted test scores

	//display average of test scores
	cout << "=======================" << endl;
	cout << "Average: " << *averageptr << endl;
	cout << "=======================" << endl;

	//free dynamically allocated memory and set pointer to nullptr
	delete[] arr;
	arr = nullptr;

    system("pause");
    return 0;
}

//function definitions

//function to validate input is input between 0 and 100, if not, ask again
double inputValidation(double score)
{
	while (score < 0 || score > 100) //if score is less than 0 or greater than 100, ask again for input
	{
		cout << "Score Must Be Between 0 and 100" << endl;
		cout << "Again Enter Score (0-100): ";
		cin >> score; //input new score for validation
	}
	return score;
}

//function to input test scores with validation for score range (0-100)
void InputTestScores(double* arr, int* sizeptr)
{
	for (int i = 0; i < *sizeptr; i++) //loop to input test scores
	{
		cout << "Enter Score for Test " << i + 1 << "(0-100): "; 
		cin >> *(arr + i);
		*(arr + i) = inputValidation(*(arr + i)); //call input validation function for current score
	}
}

//function to sort test scores in ascending order using bubble sort algorithm
void SortTestScores(double* arr, int* sizeptr)
{
	for (int i = 0; i < *sizeptr - 1; i++) //outer loop for bubble sort
	{
		for (int j = 0; j < *sizeptr - i - 1; j++) //inner loop for bubble sort
		{
			if (*(arr + j) > *(arr + j + 1)) //if current score is greater than next score, swap them
			{
				double temp = *(arr + j); //temp variable to hold current score during swap
				*(arr + j) = *(arr + j + 1); //swap current score with next score
				*(arr + j + 1) = temp; //swap next score with temp variable (current score)
			}
		}
	}
}

//function to calculate average of test scores by summing all scores and dividing by number of scores
void AverageofTestScores(double* arr, int* sizeptr, double* averageptr)
{
	//sum variablr and pointer to sum variable
	double sum = 0.0;
	double* sumptr = &sum;
	for (int i = 0; i < *sizeptr; i++) //loop to sum all test scores
	{
		*sumptr += *(arr + i); //add current score to sum variable using pointer
	}
	*averageptr = *sumptr / *sizeptr; //calculate average 
}

//function to display sorted test scores with formatting
void DisplayTestScores(double* arr, int* sizeptr)
{
	//display sorted test scores with formatting
	cout << "=======================" << endl;
	cout << "Sorted Test Scores " << endl;
	cout << "=======================" << endl;
	for (int i = 0; i < *sizeptr; i++) //loop to display sorted test scores
	{
		//display current test score with formatting
		cout << "Score for Test " << i + 1 << ": " << *(arr + i) << " " << endl;
		cout << "-----------------------" << endl;
	}
}
