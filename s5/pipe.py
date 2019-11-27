# In The Name of God
# =======================================
# [] File Name : pipe.py
#
# [] Creation Date : 27-11-2019
#
# [] Created By : Parham Alvani <parham.alvani@gmail.com>
# =======================================

import os


def child(n, pipeout):
    print('I am Child')
    f = os.fdopen(pipeout, 'w')
    f.write('hello\n')


def parent():
    pipein, pipeout = os.pipe()
    n = 10
    if os.fork() == 0:
        child(n, pipeout)
    else:
        print('I am Parent')
        f = os.fdopen(pipein, 'r')
        print(f.readline())


if __name__ == '__main__':
    parent()
