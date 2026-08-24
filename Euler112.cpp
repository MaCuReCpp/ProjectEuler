#include <iostream>

constexpr int percentage = 99;

bool increasing(int n);
bool decreasing(int n);
bool bouncy(int n);
int bouncy_percentage(int n);

int main(){
    for(int m=21780; ; m++){
        if(bouncy_percentage(m)>= percentage){
            std::cout << m << std::endl;
            break;
        }
    }
    
    return 0;
}

bool increasing(int n){
    for(; n%10;){
        if(n%10<n%100)
            return false;
        n/=10;
    }
    return true;
}

bool decreasing(int n){
    for(;n%10;){
        if(n%10>n%100&&n%100)
            return false;
        n/=10;
    }
    return true;
}

bool bouncy(int n){
    if(!increasing(n)&&!decreasing(n))
        return true;
    else
        return false;
}

int bouncy_percentage(int n){
    int num = 0;
    for(int i = 100; i<=n; ++i){
        if(bouncy(i))
            num++;
    }
    return num*100/n;
}
