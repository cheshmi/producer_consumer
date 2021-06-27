//
// Created by kazem on 6/27/21.
//

#include <thread>
#include <vector>
#include <mutex>

#ifndef THREAD_PRODUCER_CONSUMER_H
#define THREAD_PRODUCER_CONSUMER_H

class ProducerConsumer{
 std::vector<int> queue;
 std::mutex m;
public:
 ProducerConsumer(){};

 void push(int val){
  std::lock_guard<std::mutex> lock(m);
  queue.push_back(val);
 }

 bool pop(int &val){
  std::lock_guard<std::mutex> lock(m);
  if(queue.empty())
   return false;
  val = queue.back();
  queue.pop_back();
  return true;
 }

};


#endif //THREAD_PRODUCER_CONSUMER_H
