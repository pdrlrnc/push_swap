# Project Report: `pipex`

## 1. Objective

The goal of this project was to sort a stack of integers — `stack a`, using a set of moves and having access to a second empty stack — `stack b`.

## 2. Implementation Summary

- **Language:** C  
- **Key features:**  
  - Gets as input numbers, either standalone numbers or in a string.  
  - Usage: `./push_swap <args>` — `<args>` can either be plain numbers or a string with numbers.

- **Interesting design decisions:**  
  - Knowing that I was going to implement radix, immediately after parsing the arguments I normalize the values.  
  - Saving the moves on a linked list instead of printing them immediately, so that I can clean the output of useless moves.  

## 3. Challenges Faced

- **Life**  
  Life got really busy while I was working on this project — I GOT MARRIED :D — and when I came back to it two months later, I struggled a lot to understand my own code. Refactoring was tedious, but the good news is that apparently I improved a lot at coding during those two months.  

- **Linked lists**  
  First project where I really used linked lists, and although it is a simple concept that I feel super comfortable with now, the learning curve at the beginning seemed to me more like a learning plane.  

## 4. What I Learned

- Having a recipe for the steps needed to complete a project is super important — refactoring wouldn’t be possible without it.  
- Sorting algorithms — I’d never heard about radix or turk before this project.  
- Radix — The algorithm I used. First you need to normalize the list, ranking the values from 0 to n-1. Then you work through checking each bit, starting with the least significant bit (*LSB*) and ending with the most significant bit (*MSB*). To know how many bits you need, find the max index. Example: if max = 499, binary needs 9 bits. Then you distribute between stacks: for each number in `stack a`, if the *LSB* is 0 push it to `b`, otherwise rotate it (so it goes to the bottom of `stack a`). After that, you bring everything back, pushing to `a`. By this step, the stack is partially sorted by that bit. Now you need to repeat for the next bit. By the time you’re finished, `stack a` is fully sorted!  

## 5. What I’d Do Differently

- DON’T EVER finish a project and then let two months pass by.  

## 6. Future Improvements

- Implement turk for 100%. It is way harder than radix but it’s the only way to get 100%.  
- Implement a checker. In theory it wouldn’t be that hard: you get the moves and the stack as input, run the moves on the stack, and check if by the end it is sorted.  

## 7. Resources & References

- [My journey to find a good sorting algorithm for the Push_Swap 42 project](https://m4nnb3ll.medium.com/my-journey-to-find-a-good-sorting-algorithm-for-the-push-swap-42-project-4a18bc38b474)  
- [Wikipedia - Radix sort](https://en.wikipedia.org/wiki/Radix_sort)  
- [Radix Sort - Data Structure and Algorithms Tutorials](https://www.geeksforgeeks.org/dsa/radix-sort/)  
- My own tears and `gdb`  
- My friends and colleagues at 42 Lisboa  

---

**Overall, `push_swap` was a fun exercise in patience. It taught me that I’ve developed a lot in the last few months as a programmer and showed me that projects that seem huge at first can be divided into smaller steps, making them manageable. I enjoyed it a lot!**  
