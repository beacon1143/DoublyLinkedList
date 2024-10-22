#include "DoublyLinkedList.hpp"

int main() {
  try {
    constexpr size_t num = 100;
    int key = -1;
    DoublyLinkedList list;
    for (size_t i = 0; i < num; i++) {
      std::cout << "Press:\n- 1 to add number to the list\n- 2 to remove number from the list\n" <<
        "- 3 to print the list\n- 0 to delete the list and finish work\n";
      std::cin >> key;
      switch (key) {
      case 1:
        MY_TYPE inp;
        std::cout << "Input a number to add to the list:\n";
        std::cin >> inp;
        list.PushBack(inp);
        break;
      case 2:
        MY_TYPE outp;
        std::cout << "Input a number to remove from the list:\n";
        std::cin >> outp;
        list.Remove(outp);
        break;
      case 3:
        std::cout << list << "\n";
        break;
      case 0:
        i = num;
        break;
      }
    }
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
}