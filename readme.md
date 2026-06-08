# C Programming Notes

## `printf()`

`printf()` → print formatted output.

---

## Compiled vs Interpreted Languages

### Interpreted Languages

Code is generally executed statement by statement.

### Compiled Languages

The entire program is converted into machine code before execution.

One advantage of interpreted languages is that they are often easier to test and debug because you don't have to wait for the program to compile after every change.

---

## Strings and Characters

```c
char *name = "Yusuf";
```

A `char *` is commonly used to represent a string.

Strings use **double quotes**:

```c
"Hello"
```

Characters use **single quotes**:

```c
'A'
```

The types of character constants and string constants are different.

---

## Format Specifiers

C uses format specifiers when printing values.

| Data Type         | Format Specifier |
| ----------------- | ---------------- |
| int               | `%d`             |
| float             | `%f`             |
| char              | `%c`             |
| string (`char *`) | `%s`             |

---

## Newline Character

```c
\n
```

Used to move the cursor to the next line.

---

## Variable Types

In C, changing the type of an already-declared variable is not allowed.

```c
int x = 5;
x = "hello"; // Error
```

---

## Variable Declaration

A variable should only be declared once within the same code block.

```c
int x = 5;
int x = 10; // Error
```

---

## Constants

```c
const int x = 5;
```

In this case, the compiler will not allow the value of `x` to be modified.

---

## Type Conversion (Casting)

```c
(float)(x + y)
```

Cast the result of `x + y` to a `float`.

---

## Type Promotion

A good way to write:

```c
(x + y + z) / 3.0
```

This is called **type promotion** because `3.0` is a floating-point value, causing the expression to be evaluated as a floating-point calculation.

---

## `void` Type

### Function Takes No Arguments

```c
int get_integer(void)
{
}
```

Using `void` explicitly indicates that the function takes no arguments.

### Function Returns Nothing

```c
void get_integer(int a, int b)
{
}
```

Using `void` as the return type indicates that the function does not return a value.

---

## Increment and Decrement Operators

### Pre-Increment

```c
int a = ++x;
```

The value of `x` is incremented first and then stored in `a`.

### Post-Increment

```c
int b = x++;
```

The current value of `x` is stored in `b` first, and then `x` is incremented.

The same logic applies to decrement operators.

---

## Operator Precedence

Logical operator precedence:

```c
!
&&
||
```

Even though precedence rules exist, it is generally recommended to use parentheses to make intent crystal clear.

---

## Logical Operators

Logical operators are used to combine conditions.

```c
&&   // AND
||   // OR
!    // NOT
```

---

## Ternary Operator

Ternary means **three operands**.

Example:

```c
int max = a > b ? a : b;
```

Flow:

```text
condition ? value_if_true : value_if_false
```

A good application of boolean logic when choosing between two values.

---

## Data Type Sizes

The size of a data type is not guaranteed to be the same on every computer.

Typical sizes:

| Type   | Size    |
| ------ | ------- |
| char   | 1 byte  |
| float  | 4 bytes |
| double | 8 bytes |

### Notes

* `char` → single character
* `float` → single-precision floating-point number
* `double` → double-precision floating-point number

---

## `sizeof`

```c
sizeof()
```

You can use it similarly to a function, but technically it is a **unary operator**.

Example:

```c
sizeof(int)
sizeof(variable)
```

---

## `strlen()`

`strlen()` returns a value of type:

```c
size_t
```

Therefore, use:

```c
%zu
```

when printing its result.

---

## Loops

### `for` Loop

C does not have a built-in "for-each" loop.

Syntax:

```c
for (initialization; condition; final_expression)
{
}
```

Execution order:

1. Initialization executes once at the beginning.
2. Condition is checked before every iteration.
3. Loop body executes.
4. Final expression executes after every iteration.

---

### `while` Loop

The condition is checked before each iteration.

```c
while(condition)
{
}
```

---

### `do-while` Loop

The loop body always executes at least once.

The condition is checked after an iteration.

```c
do
{
}
while(condition);
```

---

## Boolean Type

Does C have a boolean type?

Yes.

A `bool` typically occupies 1 byte.

---

## `#pragma once`

```c
#pragma once
```

Adding this line to the top of a header file tells the compiler to include the file only once, even if it is referenced multiple times throughout the program.

---

## Header Guards

Header guards also prevent multiple inclusions.

```c
#ifndef MY_HEADER_H
#define MY_HEADER_H

// contents

#endif
```

`MY_HEADER_H` is a macro.

### Comparison

`#pragma once` is generally:

* Less error-prone
* Simpler to write
* Often faster

---

## Printing `sizeof()` Results

Since `sizeof()` returns a `size_t`, use:

```c
printf("%zu", sizeof(int));
```

---

# Structures (`struct`)

A structure is a **composite data type** used to group related data together.

Structures are similar to objects in the sense that they group information together, but they do not contain behavior (methods/functions).

They only store data.

---

## Accessing Struct Members

### Dot Operator

Use when you have an actual struct variable.

```c
student.name
```

### Arrow Operator

Use when you have a pointer to a struct.

```c
student_ptr->name
```

---

## Field Order Matters

The order of fields inside a structure matters because it affects the overall size of the structure due to memory alignment and padding.

---

## Struct Initialization Techniques

### Zero Initialization

```c
struct city c = {0};
```

Initializes all fields to zero.

---

### Positional Initialization

```c
struct city c = {
    "San Francisco",
    37,
    -122
};
```

Values are assigned according to the order of fields in the structure definition.

---

### Designated Initialization

```c
struct city c = {
    .name = "San Francisco",
    .lat = 37,
    .lon = -122
};
```

Explicitly specifies which field receives which value.

The syntax is:

```c
.field_name = value
```

---

## Assigning Values to Struct Fields

```c
city.name = "Mysore";
```

Reading values:

```c
printf("%s", city.name);
```

---

## `typedef` with Structures

Adding `typedef` allows the structure itself to become a data type alias.

```c
typedef struct student
{
} student_t;
```

Usage:

```c
student_t s;
```

The `_t` suffix is a common convention indicating a data type.

---

## Struct Padding

Example:

```c
#include <stdio.h>

struct some
{
    char a;
    char d;
    int e;
    float f;
    char b;
    char c;
} some;

int main()
{
    printf("%zu", sizeof(some));
    return 0;
}
```

You may notice that the structure occupies more memory than the sum of its fields.

This happens because of **padding**.

The compiler inserts extra bytes to align fields efficiently in memory.

Treat this as a feature rather than a bug.

### Rule of Thumb

Arrange fields from largest to smallest.

Example:

```c
struct example
{
    float f;
    int e;
    char a;
    char b;
};
```

This generally minimizes padding.

---

## Contiguous Memory

**Contiguous** means stored directly next to each other in memory.

Example:

```text
1000
1001
1002
1003
```

These memory locations are contiguous.
