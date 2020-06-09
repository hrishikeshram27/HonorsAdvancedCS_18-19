#include<iostream>
#include<iomanip>
#include <windows.h>
#include<string>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<math.h>
#include<cmath>

string toLow(string input){
	string lower = "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz";
	string upper = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
	string converted = "";
	for(int i=0;i<input.length();i++){
		converted += lower[upper.find(input[i])];
	}
	return converted;
}

string delSpaces(string input){
    for(int i=0;i<input.length();i++){
        if(input[i]==' '){
            input.erase(i,1);
        }
    }
    return input;
}

int strToInt(std::string input){
    int output = 0;
    int counter = input.length()-1;
    for(int i=0;i<input.length();i++){
        output += (input[i] - '0')*pow(10,counter);
        counter--;
    }
    return output;
}

void ISort(int integer[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(integer[i]>integer[j]){
                int swapper = integer[i];
                integer[i] = integer[j];
                integer[j] = swapper;
            }
        }
    }
}

void CSort(char character[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(character[i]>character[j]){
                char swapper = character[i];
                character[i] = character[j];
                character[j] = swapper;
            }
        }
    }
}

void DSort(double dub[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(dub[i]>dub[j]){
                double swapper = dub[i];
                dub[i] = dub[j];
                dub[j] = swapper;
            }
        }
    }
}

template<class potter>
void BSort(potter dub[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(dub[i]>dub[j]){
                potter swapper = dub[i];
                dub[i] = dub[j];
                dub[j] = swapper;
            }
        }
    }
}
