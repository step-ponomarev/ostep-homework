https://pages.cs.wisc.edu/~remzi/OSTEP/vm-freespace.pdf
1)
Допустил ошибку в начале и дальше все съехало, заново честно - лень

ptr[0] = Alloc(3) returned 1000
List = {addr:1003, size: 97}

Free(ptr[0])
returned = 0
List {addr:1000, size: 3}, {addr:1004, size: 97}


ptr[1] = Alloc(5) returned 1004
List {addr:1000, size: 3}, {addr:1008, size: 92}

Free(ptr[1])
returned 0
List {addr:1000, size: 3, {addr:1003, size: 5} {addr:1008, size: 92}

ptr[2] = Alloc(8) returned 1009
List {addr:1000, size: 3}, {addr:1004, size: 5} {addr:1016, size: 84}

Free(ptr[2])
returned 0
List {addr:1000, size: 3}, {addr:1003, size: 5} {addr:1009, size: 8} {addr:1017, size: 83}

ptr[3] = Alloc(8) returned 1009
List {addr:1000, size: 4}, {addr:1004, size: 5} {addr:1017, size: 83}

Free(ptr[3])
returned 0
List {addr:1000, size: 4}, {addr:1004, size: 5} {addr:1017, size: 83}

ptr[4] = Alloc(2) returned 1000
List {addr:1002, size: 2}, {addr:1004, size: 5} {addr:1017, size: 83}

ptr[5] = Alloc(7) returned 1017
List {addr:1002, size: 2}, {addr:1004, size: 5} {addr:1024, size: 76}


2) Каждый раз мы будем откусывать от самого большого куска доступной памяти

3) Результат в нашем случае будет точно такой же как при BEST_FIT
4) По убыванию - лучший результат для поиска свободного фрагмента
5) При использовании большого количества фрагментов и coalescing - нам выгоден порядок ADDRSORT т.к. мержатся ближние фрагменты.
6) При 100% аллокации наш список свободных фрагментов будет состоять не более чем из 1 элемента. 
7) Чтобы увеличить free list нужно отключить coalescing и чередовать аллокацию с освобождением, использовать worst policy и SIZESORT+