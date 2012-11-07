---
layout: page
title: Publications
---
{% include JB/setup %}

2012
----
Speziale Ettore and Michele Tartara. A Lightweight Approach to Compiling and Scheduling Highly Dynamic Parallel Programs. _In HotPar’12 (Poster), 2012_

_This paper describes a dynamic and lightweight compiler able to guide the execution of highly dynamic parallel programs at runtime without the need for a full-fledged Just-In-Time compiler.
The proposed approach allows us to apply profitable optimizations that could not be used at compile-time due to lack of sufficient information.
It also enables us to optimize code fragments multiple times, depending on the specific conditions of the execution environment at runtime, while limiting the performance overhead to a negligible amount._

* Article: [a-lightweight-approach-to-compiling-and-scheduling-art.pdf](/info/download/a-lightweight-approach-to-compiling-and-scheduling-art.pdf)
* Teaser: [a-lightweight-approach-to-compiling-and-scheduling-tsr.pdf](/info/download/a-lightweight-approach-to-compiling-and-scheduling-tsr.pdf)
* Poster: [a-lightweight-approach-to-compiling-and-scheduling-pos.pdf](/info/download/a-lightweight-approach-to-compiling-and-scheduling-pos.pdf)

---

2011
----
Paolo Roberto Grassi, Mariagiovanna Sami, Ettore Speziale, and Michele Tartara. Analyzing the Sensitivity to Faults of Synchronization Primitives. _In DFT, 2011_

_Modern multi-core processors provide primitives to allow parallel programs to atomically perform selected operations.
Unfortunately, the increasing number of gates in such processors leads to a higher probability of faults happening during the computation.
In this paper, we perform a comparison between the robustness of such primitives with respect to faults, operating at a functional level.
We focus on locks, the most widespread mechanism, and on transactional memories, one of the most promising alternatives.
The results come from an extensive experimental campaign based upon simulation of the considered systems.
We show that locks prove to be a more robust synchronization primitive, because their vulnerable section is smaller.
On the other hand, transactional memory is more likely to yield an observable wrong behaviour in the case of a fault, and this could be used to detect and correct the error.
We also show that implementing locks on top of transactional memory increases its robustness, but without getting on par with that offered by locks._

* Article: [analyzing-the-sensitivity-to-faults-of-art.pdf](/info/download/analyzing-the-sensitivity-to-faults-of-art.pdf)

Andrea di Biagio, Ettore Speziale, and Giovanni Agosta. Exploiting Thread-data Affinity in OpenMP with Data Access Pattern. _In Euro-Par, 2011_

_In modern NUMA architectures, preserving data access locality is a key issue to guarantee performance.
We define, for the OpenMP programming model, a type of architecture-agnostic programmer hint to describe the behaviour of parallel loops.
These hints are only related to features of the program, in particular to the data accessed by each loop iteration.
The runtime will then combine this information with architectural information gathered during its initialization, to guide task scheduling, in case of dynamic loop iteration scheduling.
We prove the effectiveness of the proposed technique on the NAS parallel benchmark suite, achieving an average speedup of 1.21x._

* Article: [exploiting-thread-data-affinity-in-openmp-with-art.pdf](/info/download/exploiting-thread-data-affinity-in-openmp-with-art.pdf)
* Lecture: [exploiting-thread-data-affinity-in-openmp-with-lec.pdf](/info/download/exploiting-thread-data-affinity-in-openmp-with-lec.pdf)

Ettore Speziale, Andrea di Biagio, and Giovanni Agosta. An Optimized Reduction Design to Minimize Atomic Operations in Shared Memory Multiprocessors. _In HIPS, 2011_

_Reduction operations play a key role in modern massively data parallel computation.
However, current implementations in shared memory programming APIs such as OpenMP are often computation bottlenecks due to the high number of atomic operations involved.
We propose a reduction design that exploits the coupling with a barrier synchronization to optimize the execution of the reduction.
Experimental results show how the number of atomic operations involved is dramatically reduced, which can lead to significant improvement in scaling properties on large numbers of processing elements.
We report a speedup of 1.53x on the 312.swim\_m SPEC OMP2001 benchmark and a speedup of 4.02x on the streamcluster benchmark from the PARSEC suite over the baseline._

* Article: [an-optimized-reduction-design-to-minimize-art.pdf](/info/download/an-optimized-reduction-design-to-minimize-art.pdf)
* Lecture: [an-optimized-reduction-design-to-minimize-lec.pdf](/info/download/an-optimized-reduction-design-to-minimize-lec.pdf)

__Note__: due to an error in the experimental setup, performance numbers of _streamcluster_ are not correct.
Unfortunately I spot the error few months after the paper was published.
Further measurements show that the optimization of streamcluster achieve a more modest speedup.
