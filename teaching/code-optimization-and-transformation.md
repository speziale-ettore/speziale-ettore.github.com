---
layout: page
title: Code Optimization and Transformation
---
{% include JB/setup %}

The aim of this course is to teach the internal organization of a compiler, that is compiler _middle-end_ and _back-end_.
The course is held by Professor [Stefano Crespi Reghizzi](crepi@elet.polimi.it), who is in charge of teaching compilation theory.
My duty is to teach student how theoretical concept are implemented in a real compiler.

In order to get a pass grade, students have to take an oral examination, and write a simple project about exploiting some compilation environment.

Academic Year 2011-2012
-----------------------

This year we selected LLVM as the compilation tool.
Its main strength is _modularity_: code is well organized, and playing with him it is not a big deal.
Thus we think that it is powerful teaching tools: code cleanness allow students working with it without much effort, and, at the same time, they have the
opportunity to learn a key production-quality compilation technology.

During classes, I teach student how to think when they have to write compiler-related tools.
In particular I pushed on the different kind of passes available in LLVM and how using them to implement new ones:

* [Introducing LLVM](/teaching/download/cot/2011-2012/introducing-llvm-lec.pdf)
* [LLVM Passes](/teaching/download/cot/2011-2012/llvm-passes-lec.pdf)

Students are expected to write a simple project exploiting LLVM libraries.
Assignments for current year can be downloaded here:

* [ACSE](/teaching/download/cot/2011-2012/acse.pdf)
* [Bounds Checking Elimination](/teaching/download/cot/2011-2012/bounds-checking-elimination.pdf)
* [If-Switch](/teaching/download/cot/2011-2012/if-switch.pdf)
* [List Scheuling](/teaching/download/cot/2011-2012/list-scheduling.pdf)
* [Modulo Scheduling](/teaching/download/cot/2011-2012/modulo-scheduling.pdf)
* [Program Dependence Graph](/teaching/download/cot/2011-2012/program-dependence-graph.pdf)

In order to ease development effort, I made a sample project with some simple passes.
This provides students a pre-configured environment to define new compilation passes and tools.
The project is called [COTPasses](https://github.com/speziale-ettore/COTPasses), and stored on GitHub.
