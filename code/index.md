---
layout: page
title: Code
---
{% include JB/setup %}

I always wrote a lot of code, either to evaluate whether a language or an API fits my needs, or just for fun.
I tried a lot of languages.
My opinion is that C++ is mandatory for large scale, performance-critical software.
I mean, C also fits these requirements, however ad-hoc polymorphism and a macro jungle cannot be in par with C++ built-in object-oriented features and template meta-programming.

I would like using Ruby for scripting purposes, but the huge amount of available libraries makes Python more attractive.
I like coding something in Haskell,  once in a while, and I usually perform black-magic with autotools.

Here you can find a list of projects I uploaded to GitHub.

Homepage
--------

My GitHub pages site repository.
As you can see in the footer, I just put some contents on top of [Jekyll][www/jekyll] together with a theme from [Mark Reid][www/markReid] -- thank you.

* [speziale-ettore.github.com](https://github.com/speziale-ettore/speziale-ettore.github.com)

Code Optimization and Transformation Passes
-------------------------------------------

In 2012 I was teaching assistant of the _Code Optimization and Transformation_ course, held at [Politecnico di Milano][www/polimi] by Professor [Stefano Crespi Reghizzi](mailto:crespi@elet.polimi.it).
During the classes, I show students how to exploit LLVM libraries in order to build simple compiler analyses and transformation tools.

To ease student lifes, I prepared a sample project.
It contains examples about how to define/link/test a new LLVM pass.
It is a little bit outdated, but consider that it should be used by students, so working on trunk is not an option.

* [COTPasses](https://github.com/speziale-ettore/COTPasses)

OpenCRun
--------

A long time ago, after coding a while inside GCC, I decided to try LLVM.
I was impressed by the readability of the code: anyone, with basic skills about compilers and C++ can easily understand how it works, and use it some project.

Thus I decided to write something in order to learn its API. I wrote a small OpenCL runtime for multi-core machines.
I can run simple OpenCL applications, but, unfortunately, I had not much time to work on it, so its development has been stopped.
I really hope to find some spare time in the future to continue improving on it.

* [OpenCRun](https://github.com/speziale-ettore/OpenCRun)

Beamer DEI Theme
----------------

I did the Ph.D. at Dipartimento di Elettronica e Informazione -- Politecnico di Milano.
Unfortunately, the template for slides is available only in the PowerPoint format, so I decided to try porting it to Beamer.

Code repository is on GitHub:

* [beamer-dei-v2](https://github.com/speziale-ettore/beamer-dei-v2)

Here are release tarballs and previews:

* Version 0.1: [beamer-dei-v2-0.1.tar.gz](/code/download/beamer-dei-v2/beamer-dei-v2-0.1.tar.gz), [themedei-test-0.1.pdf](/code/download/beamer-dei-v2/themedei-test-0.1.pdf)

[www/jekyll]: http://github.com/mojombo/jekyll
[www/markReid]: http://mark.reid.name
[www/polimi]: http:///www.polimi.it
