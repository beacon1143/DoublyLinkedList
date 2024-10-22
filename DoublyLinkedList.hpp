#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <iostream>
#include <memory>

using MY_TYPE = int;

class DoublyLinkedList {
private:
  struct Node {
    const MY_TYPE data;
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;
    explicit Node(const MY_TYPE _data) : data{_data}, next{nullptr} {};
    ~Node() {
      std::cout << "Node destructor working...\n";
    }
  };
  std::shared_ptr<Node> first_;
  std::shared_ptr<Node> last_;
  size_t size_;
public:
  size_t GetSize() const;
  int PushBack(const MY_TYPE inp);
  int Remove(const MY_TYPE inp);
  DoublyLinkedList();
  ~DoublyLinkedList() {}

  DoublyLinkedList(const DoublyLinkedList& other) = delete;
  DoublyLinkedList(DoublyLinkedList&& tmp) = delete;
  DoublyLinkedList& operator=(const DoublyLinkedList& other) = delete;
  DoublyLinkedList& operator=(DoublyLinkedList&& tmp) = delete;

  friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList& list);
};

#endif // SINGLY_LINKED_LIST_HPP