#include <iostream>
#include "binHeap.h"
#include <ctime>
#include <random>


using namespace std;

template <typename T>
class CheckedHeap : public MaxHeap<T>{
  using Base = MaxHeap<T>;
  public:
    CheckedHeap() : Base() {}

    template <typename RAIT>
    CheckedHeap(RAIT begin, RAIT end) : Base(begin, end) {}

    bool isHeap() const ;
};


template <typename T>
bool CheckedHeap<T>::isHeap() const {
  bool rez = true;
  auto n = this->mData.size();
  for(typename Base::size_type i=0; i < n; ++i){
     auto left = 2*i+1;
     if(left >= n) 
         break;
     if(this->mData[i] < this->mData[left]) 
       rez = false;
    
     auto right = 2*i+2;
     if(right >= n) 
         break;
     if(this->mData[i] < this->mData[right]) 
       rez = false;
  }
  return rez;
}


template <typename T>
bool isHeap(std::vector<T> const & vec) {
  bool rez = true;
  auto n = vec.size();
  for(std::size_t i=0; i < n; ++i){
     auto left = 2*i+1;
     if(left >= n) 
         break;
     if(vec[i] < vec[left]) 
       rez = false;
    
     auto right = 2*i+2;
     if(right >= n) 
         break;
     if(vec[i] < vec[right]) 
       rez = false;
  }
  return rez;
}




int main()
{

    std::vector<double> a{1.0, 3.0, 3.1, 3.01, 4.0, 9.0, 1.0};
  cout << isHeap(a) << " ";// false);

  CheckedHeap<double> h2(a.begin(), a.end());
  cout << h2.isHeap() << " "; //true);
//  h2.print(); std::cout << std::endl;
  h2.sort(a);
  cout << h2.empty() << "\n";// true);
  for(auto x : a) std::cout << x << " ";
std::cout << std::endl;

//     CheckedHeap<int> h1;
//   h1.push(2);
//   cout<<h1.isHeap()<<" ";
//   cout << "size " << h1.size() << "\n"; // 1u;
//   h1.push(7);
//   cout<<h1.isHeap()<<" ";
//   h1.push(4);
//   cout<<h1.isHeap()<<" ";
//   h1.push(9);
//   cout<<h1.isHeap()<<" ";
// //  h1.print(); std::cout << std::endl;
//   cout<<h1.isHeap()<<" ";
//   h1.pop();
//   cout<<h1.isHeap()<<" ";
//   h1.pop();
//     cout<<h1.isHeap()<<" ";
//   h1.push(3);
//     cout<<h1.isHeap()<<" ";h1.pop();  cout<<h1.isHeap()<<" ";
//   h1.pop();  cout<<h1.isHeap()<<" ";
// //  h1.print(); std::cout << std::endl;
//   h1.pop();
//     cout<<h1.empty()<<" ";  cout<<h1.isHeap()<<" ";

//   cout << "\nDrugi dio" << endl;

//   std::vector<short> a{1,3,7,3,4,9,1};
//   cout << isHeap(a) << " "; // false);

//   CheckedHeap<long> h2(a.begin(), a.end());
// //  h2.print();
//   cout << h2.isHeap() << " ";//,true);
//   h1.push(2);
//   cout << h2.isHeap() << " ";
//   h1.pop();
//   cout << h2.isHeap() << " ";
//   h1.push(7);
//   cout << h2.isHeap() << " ";
//   h1.push(4);
//   cout << h2.isHeap() << " ";


  
//TU je mData public da bi mogli testirati

  //cout << "Je li Heap prazan? " << M.empty();
  // MaxHeap<int> M;
  // M.push(5); M.push(1); M.push(18); M.push(7); M.push(4); M.push(91);
  // int podaci[] = {5,1,18,7,31,51,2,3,63,1920,411,4,91};
  // MaxHeap<int> M(podaci,podaci+13), N(podaci,podaci+13);
  // vector<int> rezultat, rez2;

  // cout << endl;

  // for(auto i : M.mData){
  //     cout << i << " ";
  // }
  // cout << endl;

  // M.sort(rezultat);

  // for(auto i : rezultat) cout << i << " ";
  // cout << endl;

  // N.pop();
  // N.pop();
  // N.pop();
  // N.pop();
  // N.pop();
    
  // cout << "Izbacili smo 5 elemenata!" << endl;

  // for(auto i : N.mData){
  //   cout << i << " ";
  // }
  // cout << endl;

  
  // N.sort(rez2);
  // cout << "Tu sam" << endl;
  // for(auto i : rez2) cout << i << " ";
  // cout << endl;
  


  return 0;
}
