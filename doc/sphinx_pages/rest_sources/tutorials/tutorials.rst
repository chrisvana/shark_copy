Tutorials
=========

.. contents:: Contents:


This page lists all tutorials available for the Shark machine learning library.
Together with a comprehensive set of example and test programs, they are
excellent starting points towards developing and evaluating machine learning
software using Shark. Also see the guide to the different documentation pages
available :doc:`here <../getting_started/using_the_documentation>`.



Very first steps
++++++++++++++++


We first show how to set up either a traditional Makefile or a CMake file
for your application program. Then we move on to a simple Hello-World example
of what linear binary classification can look like in Shark. The third tutorial
illustrates the model-error-optimizer trias often encountered in Shark through
a simple regression task.

* :doc:`first_steps/your_programs`
* :doc:`first_steps/hello_shark`
* :doc:`first_steps/general_optimization_tasks`
* :doc:`first_steps/when_to_stop`
* :doc:`concepts/misc/versatile_classification`



Overarching concepts
++++++++++++++++++++


Many generic concepts that Shark implements span across the whole library or
are relevant in many different application scenarios. We collect a number of
such generic tutorials here which explain these concepts in detail.
We believe that these are useful if you want to thoroughly familiarize yourself with Shark.
If you are looking for a quick introduction on how to set up a specific algorithm, take a look at the
component specific tutorials further down the page.

Before we can introduce the main interface classes of shark, we need to define more properly
a few basic terms as well as the design goals.

* :doc:`concepts/library_design/designgoals`
* :doc:`concepts/optimization/optimizationtrainer`
* :doc:`concepts/optimization/conventions_derivatives`
* :doc:`concepts/library_design/batches`

The main interfaces, or concepts in shark are the base classes from which nearly
all components  are derived. These tutorials are meant as a specification of the interfaces
as well as the behavior and are written in a more formal language.

* :doc:`concepts/library_design/models`
* :doc:`concepts/library_design/losses`
* :doc:`concepts/library_design/optimizers`
* :doc:`concepts/library_design/objective_functions`
* :doc:`concepts/library_design/stopping_criteria`
* :doc:`concepts/library_design/trainers`
* :doc:`concepts/library_design/kernels`
* :doc:`concepts/library_design/writing_kernels`
* :doc:`concepts/library_design/writing_objective_functions`



Data Handling
+++++++++++++


.. _label_for_data_tutorials:

Since many machine learning algorithms work on real-world datasets, we extensively
cover Shark's :doxy:`Data` class as well as common operations on them:

* :doc:`concepts/data/datasets`
* :doc:`concepts/data/labels`
* :doc:`concepts/data/import_data`
* :doc:`concepts/data/dataset_subsets`
* :doc:`concepts/data/normalization`



Specific algorithms
+++++++++++++++++++


Here come tutorials for some selected algorithms implemented in Shark.
It must be said that this is only the tip of the iceberg, *many* more
machine learning algorithms and tools are provided by the library.

Let's start with some classical methods:

* :doc:`algorithms/pca`
* :doc:`algorithms/nearestNeighbor`
* :doc:`algorithms/lda`
* :doc:`algorithms/linearRegression`
* :doc:`algorithms/kmeans`

Neural nets:

* :doc:`algorithms/ffnet`
* :doc:`algorithms/sparse_ae`
* :doc:`algorithms/extreme_learning_machine`
* :doc:`algorithms/rbm_module`
* :doc:`algorithms/binary_rbm`

Tree-based algorithms:

* :doc:`algorithms/cart`
* :doc:`algorithms/rf`

Kernel methods -- support vector machine training and model selection:

* :doc:`algorithms/svm`
* :doc:`algorithms/svmModelSelection`
* :doc:`algorithms/svmLikelihoodModelSelection`
* :doc:`algorithms/lkc-mkl`

Direct search methods -- the covariance matrix adaptation evolution strategy:

* :doc:`concepts/optimization/directsearch`
* :doc:`algorithms/cma`
* :doc:`algorithms/mocma`



Tools
+++++


Finally, we present functionality which are not machine learning facilities
themselves, but necessary or helpful tools.

First of all there is Sharks own solver for Quadratic Programs:

* :doc:`algorithms/quadratic_programs`

.. _label_for_linalg_tutorials:

We give an introduction to Shark's usage of the
`Boost uBLAS <http://www.boost.org/doc/libs/release/libs/numeric>`_
library for "all things linear algebra":

* :doc:`concepts/lin_alg/vector_matrix`
* :doc:`concepts/lin_alg/lapack`

For convenience, Shark provides a statistics class wrapper, as well as generic
support for serialization, logging, and the well-known factory-method-pattern:

* :doc:`concepts/misc/statistics`
* :doc:`concepts/misc/logging`
* :doc:`concepts/misc/factory`
* :doc:`concepts/misc/serialization`


Finally, there is a self-written web server add-on available for Shark. It
does not depend on Shark in any way, but can be helpful to achieve in-browser
GUI visualization without further dependencies. The rationale for this, the
web server's primary intended uses, and all technical specifics are
described in the corresponding tutorial:

* :doc:`addon/webserver`



For Shark developers
++++++++++++++++++++


Note that Shark follows a

* :doc:`for_developers/codingconvention`.

If you contribute to Shark, you might also find these documents helpful:

* :doc:`for_developers/the_build_system`
* :doc:`for_developers/development_environment`
* :doc:`for_developers/effective_ublas`
* :doc:`for_developers/writing_tutorials`
* :doc:`for_developers/managing_the_documentation`
* :doc:`for_developers/issuing_a_release`


