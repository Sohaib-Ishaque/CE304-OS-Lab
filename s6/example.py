# In The Name of God
# =======================================
# [] File Name : example.py
#
# [] Creation Date : 27-11-2019
#
# [] Created By : Parham Alvani <parham.alvani@gmail.com>
# =======================================

import threading

lock = threading.Lock()


def say_hello(n):
    for i in range(0, 10):
        lock.acquire()
        print(f'Thread {n}: {i}')
        lock.release()


if __name__ == '__main__':
    t1 = threading.Thread(target=say_hello, args=(1,))
    t2 = threading.Thread(target=say_hello, args=(2,))

    t1.start()
    t2.start()
