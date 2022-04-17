#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if(size_ <= 1) return;

    Node* node = front_;
    Node* a = front_;
    Node* prev = nullptr;
    Node* nextNode = node->next;
    for(int i = 0; i < size_; ++i){
      nextNode = node->next;
      node->next = prev;
      prev = node;
      node = nextNode;
    }
    front_ = prev;
    back_ = a;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if(size_ > 1) {
      Node* curr = front_;
      Node* a = front_;
      Node* prev = nullptr;
      reverse_recursive_helper(curr, prev);
      front_ = back_;
      back_ = a;
    }
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if(curr == nullptr) {
      return;
    }
    Node* nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
    reverse_recursive_helper(curr, prev);
  }

}  // namespace assignment
