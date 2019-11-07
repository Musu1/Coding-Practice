#include <bits/stdc++.h>

using namespace std;

/*
Function: gradingStudents
Input: integer array
Return type:integer array
Thisfunction rounds up the grades inthe input array according the roulegiven in question and gives a rounded array.

*/

vector<int> gradingStudents(vector<int> grades) {
    int size=grades.size(); //calculates the size of the array grades
    vector<int> gradesi(size); //creates a array to store rounded grades
    for(int i=0;i<=size;i++){
        if(grades[i]<38){
            gradesi[i]=grades[i];
        }
        else{
            int next= 5 - (grades[i] % 5); // Logic to calculate the difference between the number                                                and next multiple of 5
            if(next<3){
                gradesi[i]=grades[i]+next;
            }
            else{
                gradesi[i]=grades[i];
            }
        }
        
    }
    return gradesi;

}

/*
Main function
Input: Takes input from user, First line should be how many grades to enter and subsequent lines are grade of students
Output: Rounded grade array
Function: calls gradingStudent funcion declaredabove to calculate the rounded grades
*/
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n; // No. of grades user wants to enter
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //This sets cin that there is no limit to no. of characters to ignore and /n is a delimiter that is after this cin stops ignoring

    vector<int> grades(n); // Array defined to store the grades inputed by the user

    for (int grades_itr = 0; grades_itr < n; grades_itr++) {
        int grades_item;
        cin >> grades_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        grades[grades_itr] = grades_item;
    }

    vector<int> result = gradingStudents(grades); //Output rounded grade array

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}