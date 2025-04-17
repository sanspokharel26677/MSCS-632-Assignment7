# 📊 MSCS-632 Assignment 7 – Statistics Calculator (Multi-Paradigm)

This project is part of **MSCS-632: Advanced Programming Languages** and demonstrates how the same computational problem—calculating **mean**, **median**, and **mode** of a list of integers—can be solved using **three different programming paradigms**:

- ✅ **Python (Object-Oriented Programming)**
- ✅ **C (Procedural Programming)**
- ✅ **OCaml (Functional Programming)**

Each version takes user input and prints out the calculated results.

---

## 🧠 Problem Statement

Given a list of integers, calculate:
- **Mean** – average value
- **Median** – middle value of sorted list
- **Mode** – most frequent number(s)

---

## 📁 Folder Structure

```
MSCS-632-Assignment7/
├── c-version/
│   └── statistics_calculator.c
├── ocaml-version/
│   └── statistics_calculator.ml
├── python-version/
│   └── statistics_calculator.py
└── README.md
```

---

## 🛠 How to Run the Project

---

### 🐍 Python Version (python-version)

**Install Python (Mac/Linux):**
```bash
sudo apt install python3       # Linux (Ubuntu/Debian)
brew install python            # macOS (Homebrew)
```

**Run the program:**
```bash
cd python-version
python3 statistics_calculator.py
```

You’ll be prompted to enter integers separated by space.

---

### 🧱 C Version (c-version)

**Install GCC Compiler:**
```bash
sudo apt install build-essential    # Linux
brew install gcc                    # macOS
```

**Compile and Run:**
```bash
cd c-version
gcc statistics_calculator.c -o stats
./stats
```

---

### 🌀 OCaml Version (ocaml-version)

**Install OCaml on macOS/Linux:**
```bash
brew install opam                   # macOS
sudo apt install opam               # Linux
opam init
eval $(opam env)
opam switch create 4.14.0           # or latest version
eval $(opam env)
```

**Compile and Run the Program:**
```bash
cd ocaml-version
ocamlc -o stats statistics_calculator.ml
./stats
```

You’ll be asked to enter space-separated integers.

---

## 💡 Sample Input

Use any of these sample inputs to test all versions:

```
4 2 5 2 3 5 2
10 15 10 20 30 15 10 25
7 7 2 2 5 6
8 6 6 8 7 7
```

---

## 🔗 GitHub Repository

This project is hosted at:  
📎 https://github.com/sanspokharel26677/MSCS-632-Assignment7

---

## ✍️ Author

**Sandesh Pokharel**  
Master’s in Computer Science  
University of the Cumberlands
