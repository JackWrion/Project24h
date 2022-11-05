#include <iostream>
#include <string>

using namespace std;


string suffixWithUnit ( double number ){
    if (number < 1000){
        return to_string((int)number);
    }
    else if (number < 1000000){
        int WholeNum = number/1000;
        int frac = (int)number%1000;

        if (frac == 0) return to_string(WholeNum)+" Kilo";
        else return to_string(WholeNum)+ "." + to_string(frac) + " Kilo";
    }
    else if (number < 1000000000){
        int WholeNum = number/1000000;
        int frac = (int)number%1000000;
        if (frac == 0) return to_string(WholeNum)+" Mega";
        return to_string(WholeNum)+ "." + to_string(frac) + " Mega";
    }
    else{
        int WholeNum = number/1000000000;
        long long frac = (long long)number%1000000000;
        if (frac == 0) return to_string(WholeNum)+" Giga";
        return to_string(WholeNum)+ "." + to_string(frac) + " Giga";
    }
}

int main()
{
    cout<<suffixWithUnit(1000);

    return 0;
}
