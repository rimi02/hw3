#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <iostream>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
 Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
    int m;
    PComparator c;
    std::vector<T> nHeap;
    void heapify(size_t i, PComparator c);
    void swap(size_t i, size_t j);




  
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
{
    this->m = m;
    this->c = c;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  // Add code to return the size of the heap
    return nHeap.size();
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  // Add code to return true if the heap is empty
  // and false otherwise
    if (nHeap.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");




  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

    return nHeap[0];

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(size_t i, PComparator c)
{
    size_t smallest = i;
    size_t child = m*i+1;
    for (size_t j = 0; j < m; j++)
    {
        if (child+j < nHeap.size() && c(nHeap[child+j], nHeap[smallest]))
        {
            smallest = child+j;
        }
    }
    if (smallest != i)
    {
        std::swap(nHeap[i], nHeap[smallest]);
        heapify(smallest, c);
    }
    
}








// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");

  }
    else
    {
        nHeap[0] = nHeap[nHeap.size()-1];
        nHeap.pop_back();
        heapify(0, c);
    }
    

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
    nHeap.push_back(item);
    size_t i = nHeap.size()-1;
    while (i > 0 && c(nHeap[i], nHeap[(i-1)/m]))
    {
        std::swap(nHeap[i], nHeap[(i-1)/m]);
        i = (i-1)/m;
    }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::swap(size_t i, size_t j)
{
    T temp = nHeap[i];
    nHeap[i] = nHeap[j];
    nHeap[j] = temp;
}






#endif












