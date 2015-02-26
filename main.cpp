//===========================================================
// Kevin Mata
// Compiler: g++
// Description: This program will take 3 integers from the user and place them into a vector L1,
//and will prompt the user for 3 more integers and place them into L2. 
//Then we call a function in order to combine ans sort the intgers in 
//the vector in ascending order using merge sort.
//===========================================================

#include    <iostream>
#include    <stdexcept>
#include    <vector>

using namespace std;

/*
 // Algorithm: The first element of the array A is compared with the first element of array B
 // IF the first element of the array is smaller than the first element of array B 
 // The element from array A is moved to the new array C.
 // the subscript of Array A is increased and the first element is now set.
 // If the element from array B is smaller it is moved into the new array C
 // The subscript of array B is increased until either array A or array B is empty
 // when one array is empty and elements remaining in the other arrays are pushed
 // into the end of array C.
 */


void combineVectors(vector<int> A, vector<int> B, vector<int> &R){
    int indexA = 0; //initialize variables for the subscripts
    int indexB = 0;
    int indexR = 0;
    
    int comparisons = 0;
    
    while((indexA < A.size()) && (indexB < B.size())){
        comparisons++;
        cout << "Number of Comparisons: " << comparisons << endl;
        if(A[indexA] < B[indexB]){
            R.push_back(A[indexA++]); 
                                    
        }
        else{
            R.push_back(B[indexB++]);     
                        
        } 
        indexR++; //move to the next position in the new array
    }
    
    //move the remaining elements to the end of the new array when one merging array is empty
    while(indexA < A.size()){
        R.push_back(A[indexA++]);
        indexR++;
        
    }
    
    while(indexB < B.size()){
        R.push_back(B[indexB++]);
        indexR++;      
        
    }
    
}

int main(void)
{
  vector <int> L1; //initialize vectors
  vector <int> L2; 
  vector <int> L3; 
  int readData;    //stores the input from the
  int maxInput = 3;
  try {
      for(int i=0;i<maxInput;i++){ 
        cout << "Enter three integers in increasing order: ";
        cin >> readData;
        L1.push_back(readData);
      }
      for(int j=0;j<maxInput;j++){
        cout << "Enter three MORE integers in increasing order: ";
        cin >> readData;
        L2.push_back(readData);
      }
    combineVectors(L1,L2,L3);
    for(int i=0;i<L3.size();i++){
        cout << L3[i] << " " << endl;
    }

  } catch (exception* e) {
      cout << "An error occurred !" << endl;
    return -1;
  }
  return(0);
}

