#include <iostream>
#include <thread>

void producer(int n){
 std::thread::id this_id = std::this_thread::get_id();
 for (int i = 0; i < n; ++i) {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout<<" producer from thread "<< this_id <<"\n";
 }
}

void consumer(int n){
 std::thread::id this_id = std::this_thread::get_id();
 for (int i = 0; i < n; ++i) {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout<<" consumer from thread "<< this_id <<"\n";
 }
}

int main() {
 std::cout << "Hello, World!" << std::endl;
 std::thread p(producer, 10);
 std::thread c(consumer, 8);

 p.join();
 c.join();

 return 0;
}




