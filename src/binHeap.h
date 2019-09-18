#ifndef MAXHEAP_H
#define MAXHEAP_H


#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>

// Predložak klase koji implementira maximalnu hrpu. 
template <typename T>
class MaxHeap{
public:
    using size_type = typename std::vector<T>::size_type;
	// Konstruktor
    MaxHeap() = default;
    // Parametrizirani konstruktor koji preuzima elemente iz raspona [begin, end).
    template <typename RAIT>
    MaxHeap(RAIT begin, RAIT end);
	// Gurni novi element na hrpu.
    void push(T);
	// Ukloni vodeći (maksimalni) element sa hrpe.
    void pop();
	// Vrati vodeći element hrpe.
    T top() const;
    // Je li hrpa prazna?
    bool empty() const;
	// Broj elemenata u hrpi.
    size_type size() const;
    // Ispiši sortirane vijednosti u vektor vec. 
	// MaxHeap ostaje prazan nakon sortiranja.
    void sort(std::vector<T> & vec);
    
protected:
    std::vector<T> mData;
    // Eventualne dodatne metode stavljati u ovu sekciju.
    void correct_heap (size_type k);
};

template<typename T>
void MaxHeap<T>::correct_heap(typename MaxHeap<T>::size_type k){

    size_type j = 2*k + 1, velicina = this->size();
    T x = mData[k];

    while( j <= velicina -1){
        if( (j<velicina-1) && (mData[j] < mData[j+1]) )j++;
        if( x >= mData[j] ) break;
        mData[(j-1)/2] = mData[j];
        j = 2*j +1;
    }
    mData[(j-1)/2] = x;

}

template <typename T>
template <typename RAIT>
MaxHeap<T>::MaxHeap(RAIT begin, RAIT end) : mData(begin,end){
    // std::cout << "Prije uredivanja : ";
    // for(auto i : mData) std::cout << i << " ";
    // std::cout << std::endl;
    if(mData.size()!=0){
        //std::cout << "KONSTRUKTOR size=" << mData.size() << std::endl;
        for( size_type k = (mData.size()/2 - 1); ; --k ){
            //std::cout << "k = " << k << std::endl;
            correct_heap(k);
            if ( k==0 ) break;
        }
    }

}

template <typename T>
void MaxHeap<T>::push(T elem){
  mData.push_back(elem);
  size_type i = mData.size() - 1;
  while (i != 0){
      if( mData[i] > mData[(i-1)/2] ){
          std::swap(mData[i],mData[(i-1)/2]);
          i = (i-1)/2;
      }
      else break; //nasli smo mu pravu poziciju
  }
}

template <typename T>
void MaxHeap<T>::pop(){
    if(!empty()){
        std::swap(mData.front(),mData.back());
        mData.pop_back();
    //   size_type i = 0, j;
    //   while ( i <= (mData.size()/2 -1) ){
    //       if( (2*i+2)==mData.size() || (mData[2*i+1] >= mData[2*i+2]) ){
    //          j = 2*i + 1;
    //       }
    //       else j = 2*i + 2;
    //       if(mData[i]<mData[j]){
    //            std::swap(mData[i],mData[j]);
    //            i = j;
    //       }
    //       else break; //nasli smo mu pravu poziciju
    //   }
        if(!empty())
            correct_heap(0);
    }
}

template <typename T>
bool MaxHeap<T>::empty() const {
  return mData.empty();
}

template <typename T>
T MaxHeap<T>::top() const{
    if (!this->empty())
        return mData.front();
    else exit(132);
}



template <typename T>
typename MaxHeap<T>::size_type MaxHeap<T>::size() const {
  return mData.size();
}

template <typename T>
void MaxHeap<T>::sort(std::vector<T> & vec){
  vec.clear();
  while(!this->empty()){
    vec.push_back(this->top());
    this->pop();
  }
  std::reverse(vec.begin(),vec.end());
}



#endif
