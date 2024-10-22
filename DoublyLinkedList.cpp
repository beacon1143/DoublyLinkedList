#include "DoublyLinkedList.hpp"

size_t DoublyLinkedList::GetSize() const {
  return size_;
}

int DoublyLinkedList::PushBack(const MY_TYPE inp) {
  try {
    if (size_ == 0) {
      first_ = std::make_shared<Node>(inp);
      last_ = first_;
    }
    else {
      if (last_ == nullptr) {
        throw std::runtime_error("Error! In DoublyLinkedList::Push!\n");
      }
      last_->next = std::make_shared<Node>(inp);
      last_->next->prev = last_;
      last_ = last_->next;
    }
    size_++;
    return 0;
  }
  catch (const std::bad_alloc& e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
}

int DoublyLinkedList::Remove(const MY_TYPE inp) {
  if (size_ == 0) {
    std::cout << "Nothing to remove, the list is empty!\n";
    return 1;
  }
  if (first_->data == inp) {
    if (size_ == 1) {
      first_ = nullptr;
      last_ = nullptr;
    }
    else {
      first_ = first_->next;
    }
    size_--;
    return 0;
  }
  auto tmp = first_;
  if (tmp == nullptr) {
    throw std::runtime_error("Error! In DoublyLinkedList::Remove!\n");
  }
  while (tmp->next != nullptr) {
    if (tmp->next->data == inp) {
      tmp->next = tmp->next->next;
      size_--;
      if (tmp->next == nullptr) {
        last_ = tmp;
      }
      else {
        tmp->next->prev = tmp;
      }
      return 0;
    }
    tmp = tmp->next;
  }
  std::cout << "Not found this number in the list!\n";
  return 0;
}


DoublyLinkedList::DoublyLinkedList() {
  first_ = nullptr;
  last_ = nullptr;
  size_ = 0;
}

std::ostream& operator<<(std::ostream& out, const DoublyLinkedList& list) {
  if (list.GetSize() == 0) {
    out << "No elements in the list!\n";
    return out;
  }
  auto tmp = list.first_;
  if (tmp == nullptr) {
    throw std::runtime_error("Error! In DoublyLinkedList::operator<<!\n");
  }
  while (tmp->next != nullptr) {
    out << tmp->data << " ";
    tmp = tmp->next;
  }
  out << tmp->data << "\n";
  return out;
}