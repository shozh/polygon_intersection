# Пересечение многоугольников

## Описание

Программа main.cpp выводит результат пересечения нескольких выпуклых многоуольников, а именно:
- точки пересечения,
- площадь пересечения.

## Запуск

1. Скачайте репозиторий
```
git clone https://github.com/shozh/polygon_intersection.git
cd polygon_intersection
```


2. Запуск программы
```
clang++ -std=c++23 main.cpp r.cpp segline.cpp convex_polygon.cpp -o main && ./main
```

## Тесты

1.
<img src=".pics/1.jpg" alt="1.jpg" width="60%" height="60%"/>

Ввод:
```cpp
ConvexPolygon A = {{1, 2}, {1, 4}, {4, 3}, {4, 4}};
ConvexPolygon B = {{4, 1}, {4, 2}, {7 ,2}};

vector<ConvexPolygon> v = {A, B};

intersects(v);
```
Вывод:
```plain
Нет пересечения!
```

2.
<img src=".pics/2.jpg" alt="1.jpg" width="60%" height="60%"/>

```cpp
ConvexPolygon A =  {{0, 0}, {7, 0}, {7, 7}};
ConvexPolygon B = {{3, 4}, {5, 0}, {13, 4}};
ConvexPolygon C = {{1, 3}, {10, 0}, {7, 6}};

vector<ConvexPolygon> v = {A, B, C};

intersects(v);
```

```plain
Точки персечения: (3.333, 3.333); (4, 4); (7, 4); (7, 1); (4, 2); 
Площадь пересечения: 8.167.
```



3.
<img src=".pics/3.jpg" alt="1.jpg" width="60%" height="60%"/>

Ввод
```cpp
ConvexPolygon A = {{1, 1}, {8, 1}, {8, 5}, {1, 5}};
ConvexPolygon B = {{1, 2}, {5, 1}, {7, 5}};
ConvexPolygon C = {{3, 2}, {3, 4}, {7, 2}, {4, 5}};

vector<ConvexPolygon> v = {A, B, C};

intersects(v);
```

Вывод:
```plain
Точки персечения: (3, 2); (3, 3); (5, 4); (6, 3); (5.5, 2); 
Площадь пересечения: 4.25.
```

4. 
<img src=".pics/4.jpg" alt="1.jpg" width="60%" height="60%"/>

Ввод:

```cpp
ConvexPolygon A = {{1, 1}, {9, 5}, {1, 5}};
ConvexPolygon B = {{3, 1}, {3, 5}, {7, 2}};
ConvexPolygon C = {{3, 2}, {5, 3}, {5, 0}};

vector<ConvexPolygon> v = {A, B, C};

intersects(v);
```

Вывод:

```plain
Точки персечения: (3, 2); (5, 3); 
Длина пересечения: 2.236.
```

5.
<img src=".pics/5.jpg" alt="1.jpg" width="60%" height="60%"/>

Ввод:

```cpp
ConvexPolygon A = {{-2, 0}, {0, 2}, {-2, 3}};
ConvexPolygon B = {{0, 0}, {2, 0}, {0, 2}};
ConvexPolygon C = {{0, 2}, {0, 4}, {2, 4}};

vector<ConvexPolygon> v = {A, B, C};

intersects(v);
```

Вывод:

```plain
Точка пересечения: (0, 2)
```