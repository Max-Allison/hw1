#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

void ULListStr::push_back(const std::string& val) {
  if (tail_ != NULL) {
    if (tail_->last == ARRSIZE) {
      tail_->next = new Item();
      tail_->next->prev = tail_;
      tail_ = tail_->next;
    }
  } else {
    tail_ = new Item();
    head_ = tail_;
  }
  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;
}

void ULListStr::pop_back() {
  if (!empty()) {
    if (tail_->last - tail_->first == 1) {
      if (tail_ != head_) {
        Item* temp = tail_;
        tail_ = tail_->prev;
        tail_->next = NULL;
        delete temp;
        size_--;
      }
      else {
        delete tail_;
        head_ = NULL;
        tail_ = NULL;
        size_--;
      }
    } else {
      tail_->last--;
      size_--;
    }
  }
}

void ULListStr::push_front(const std::string& val) {
  if (head_ != NULL) {
    if (head_->first == 0) {
      head_->prev = new Item();
      head_->prev->next = head_;
      head_ = head_->prev;
      head_->first = ARRSIZE;
      head_->last = ARRSIZE;
    }
  } else {
    head_ = new Item();
    tail_ = head_;
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
  }
  head_->first--;
  head_->val[head_->first] = val;
  size_++;
}

void ULListStr::pop_front() {
  if (!empty()) {
    if (head_->last - head_->first == 1) {
      if (head_ != tail_) {
        Item* temp = head_;
        head_ = head_->next;
        head_->prev = NULL;
        delete temp;
        size_--;
      } else {
        delete head_;
        head_ = NULL;
        tail_ = NULL;
        size_--;
      }
    } else {
      head_->first++;
      size_--;
    }
  }
}

std::string const& ULListStr::back() const {
  if (!empty()) {
    return tail_->val[tail_->last-1];
  } else {
    throw std::out_of_range("Empty List");
  }
}

std::string const& ULListStr::front() const {
  if (!empty()) {
    return head_->val[head_->first];
  } else {
    throw std::out_of_range("Empty List");
  }
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_) {
    return NULL;
  }
  Item* temp = head_;
  while (temp != NULL) {
    int count = temp->last - temp->first;
    if (loc < count) {
      return &temp->val[temp->first + loc];
    } else {
      loc -= count;
      temp = temp->next;
    }
  }
}
