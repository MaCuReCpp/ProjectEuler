#include <iostream>
#include <vector>
#include <map>

constexpr int NUM = 100000;
int rad[NUM+1];

int main(){
    // rad[]를 초기화
    for(int i=0;i<=NUM;++i){
        rad[i] = 1;
    }
    // rad[]를 실제 값과 같게 대입
    for (int p = 2; p <= NUM; ++p) {
        if (rad[p] == 1) {          // 아직 아무 소인수도 안 곱해졌으면 p는 소수
            for (int k = p; k <= NUM; k += p) {
                rad[k] *= p;        // p가 k의 소인수이므로 한 번만 곱함
            }
        }
    }
    
    // 실제로 벡터에 순서쌍 넣기
    std::vector<std::pair<int, int>> v;

    for (int n = 1; n <= NUM; ++n) {
        v.push_back({rad[n], n});
    }
    // 순서쌍 순서대로 배열
    // std::pair는 first순으로 우선 오름차순 배열 & 같으면 second로 오름차순 배열
    std::sort(v.begin(), v.end());
    
    std::cout << v[10000-1].second << std::endl;
}
