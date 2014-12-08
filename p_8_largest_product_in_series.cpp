#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

double getMaxProductSequence(const vector<int>& num, const int k){
    double maxProduct = 0;
    queue<int> slidingWindow;

    int iter = 0;
    double currProduct = 1;
    while(iter < num.size()){
        if(num[iter]==0){
            while(!slidingWindow.empty()){
                slidingWindow.pop();
            }
            currProduct = 1;
        }
        else{
            if(slidingWindow.size()==k){
                currProduct /= slidingWindow.front();
                slidingWindow.pop();
                currProduct *= num[iter];
                slidingWindow.push(num[iter]);
            }
            else{
                currProduct *= num[iter];
                slidingWindow.push(num[iter]);
            }

            if(slidingWindow.size()==k && currProduct>maxProduct){
                maxProduct = currProduct;
                cout << "The current max product: " << maxProduct << " is found at"
                     << "(" << iter-k+1 << "," << iter << ")." << endl;
                for(int i=iter-k+1; i<iter; i++){
                    cout << num[i] << " x ";
                }
                cout << num[iter] << endl;
            } 
        }
        iter++;
    }

    return maxProduct;
}

int main(){
    vector<int> array;

    ifstream inputFile;
    inputFile.open("p_8_input.txt");

    while(!inputFile.eof()){
        string inputStr;
        getline(inputFile, inputStr);

        for(char i: inputStr){
            array.push_back(static_cast<int>(i)-48);
        }
    }

    inputFile.close();

    const int windowSize = 13;

    cout << getMaxProductSequence(array, windowSize) << endl;

    return 0;
}