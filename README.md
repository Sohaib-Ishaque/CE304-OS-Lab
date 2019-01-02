# OS-Lab
[![Travis branch](https://img.shields.io/travis/com/AUT-CEIT/OS-Lab/master.svg?style=flat-square)](https://travis-ci.com/AUT-CEIT/OS-Lab)

## Introduction
Operating Systems Laboratory Materials. In this course we try to do some C and system programming with tase of bash in Ubuntu.

## Syllabus
1. Introduction
2. Processes
3. Introduction to Bash (Taher Ahmadi)
4. Inter Process Communication
5. Threads
6. Thread Synchronization
7. TCP Client & Server
8. Final Project
9. Theoretical Exam

## Final Project
Students built a synchronized queue earlier. They use this with the sample client-server application,
that they learned it in the TCP programming session, for adding a pipeline to the requests handling stage
of their TCP's client-server application.

As an example when a request comes, the program accepts then adds it into the queue.
Handlers are in the running state and read the shared queue within a loop, therefore,
they read the request in the random fashion next send its response.
