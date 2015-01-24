#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Point{
public:
    double x, y;
    Point(){}
    Point(double in_x, int in_y): x(in_x), y(in_y){}
    Point(const Point& in_p){
        x = in_p.x;
        y = in_p.y;
    }
};

class Triangle{
public:
    Point p1, p2, p3;
    double area;
    
    Triangle(){
        p1 = Point(0,0);
        p2 = Point(0,0);
        p3 = Point(0,0);
        area = 0;
    }
    Triangle(Point in_p1, Point in_p2, Point in_p3): p1(in_p1), p2(in_p2), p3(in_p3){
        area = computeArea();
    }

    double computeArea(){
        double dArea = ((p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y))/2.0;
        return (dArea > 0.0) ? dArea : -dArea;
    }

    bool isInside(Point p4);
};

bool Triangle::isInside(Point p4){
    double epsilon = 0.001;
    Triangle tri124(p1, p2, p4);
    Triangle tri234(p2, p3, p4);
    Triangle tri134(p1, p3, p4);
    if((tri124.area + tri134.area + tri234.area - area) < epsilon){
        return true;
    }
    else return false;
}

vector<string> splitString(string s, string delim){
    vector<string> allSubStr;
    auto start = 0U;
    auto end = s.find(delim);
    
    while (end != string::npos){
        allSubStr.push_back( s.substr(start, end - start) );
        // cout << s.substr(start, end - start) << endl;
        start = end + delim.length();
        end = s.find(delim, start);
    }
    allSubStr.push_back( s.substr(start, end) );
    // cout << s.substr(start, end);

    return allSubStr;
}


int main(){

    int insideCount = 0;

    ifstream inputFile;
    inputFile.open("p_102_input.txt");
    while(!inputFile.eof()){
        string inputStr;
        getline(inputFile, inputStr);

        vector<string> allSubStr = splitString(inputStr, ",");
        vector<double> allNum;
        for(string s: allSubStr){
            allNum.push_back(stoi(s));
        }
        
        // Start checking
        Point p1(allNum[0],allNum[1]);
        Point p2(allNum[2],allNum[3]);
        Point p3(allNum[4],allNum[5]);
        Triangle tri(p1, p2, p3);
        if(tri.isInside( Point(0,0) )) insideCount++;

    }

    inputFile.close();

    cout << "There are " << insideCount << " triangles containing (0,0). " << endl;

    return 0;
}