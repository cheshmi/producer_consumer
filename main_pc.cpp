//
// Created by kazem on 6/27/21.
//

#include "producer_consumer.h"
#include <iostream>

static int g_val = 0;
void producer(ProducerConsumer *pc, int n){
 std::thread::id this_id = std::this_thread::get_id();
 for (int i = 0; i < n; ++i) {
  pc->push(g_val);
  std::cout<<" producer from thread "<< this_id << " produced: "<<g_val<<" \n";
  std::this_thread::sleep_for(std::chrono::seconds(1));
  g_val++;
 }
}

void consumer(ProducerConsumer *pc, int n){
 std::thread::id this_id = std::this_thread::get_id();
 for (int i = 0; i < n; ++i) {
  int res = 0;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  if (!pc->pop(res)){
   std::cout<<" nothing to consuem :( \n";
  }
  std::cout<<"consumes "<<res << " in thread "<< this_id <<"\n";
 }
}

int main() {
 std::cout << "Hello, World!" << std::endl;

 ProducerConsumer *pc = new ProducerConsumer();
 std::thread p(producer, pc, 10);
 std::thread c(consumer, pc, 8);

 p.join();
 c.join();

 return 0;
}

