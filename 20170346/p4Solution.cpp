#include "p4Solution.hpp"
//#include <algorithm>
/* Write Your Code Below*/
/* You Can Decalre anoter Function In this file */

bool ans = false;
bool sig = false;


template <class InputIt, class T>
bool find(InputIt first, InputIt last, const T& value) {
  for (; first != last; ++first) {
    if (*first == value) {
      return true;
    }
  }
  return false;
}


void jump(vector<int>& stones, int a,int k, int c)
{

    while(a != stones[c]) //철수가 자신의 위치를 찾는다.
        {
            c++; //memo-ization
        }

    if(a == stones[stones.size()-1]) //철수가 마지막 돌에 위치하면 ans는 true로 변환되고 함수는 종료된다.
        {
            //cout << a << " "<< k << endl;
            ans = true;
            sig = true;
            return;
        }

    while(sig == false)
    {
        
        if(find(stones.begin()+c+1,stones.end(),a+k+2)){
            jump(stones, a+k+2,k+2,c);
        }
    
        if(find(stones.begin()+c+1,stones.end(),a+k+1)){
            jump(stones, a+k+1,k+1,c);
        }
        
        if(find(stones.begin()+c+1,stones.end(),a+k) && k > 0){
            jump(stones, a+k, k,c);
        }
        
        if(find(stones.begin()+c+1,stones.end(),a+(k-1)) && k-1 > 0){
            jump(stones, a+(k-1),k-1,c);
        }
        
        if(find(stones.begin()+c+1,stones.end(),a+(k-2)) && k-2 > 0){
            jump(stones, a+(k-2),k-2,c);
        }


        if(stones[c+1] > a+k+2){
            sig = true;
            break;
        }

        break;
    }

    return;
}



bool Solution::IsPossible(vector<int>& stones) 
{
    int a = 0; //철수가 현재 위치한 돌의 위치
    int c = 0; //철수가 현재 위치한 돌이 배열에서 몇번째인지
    int k = 0; // 철수가 이전에 점프한 거리
    jump(stones, a, k, 0); //첫 점프가 0일때
    return ans;   
}


