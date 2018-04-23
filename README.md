# Starlings Murmuration Simulation Software

This repository holds the mathematical model and source files of an Starlings Murmuration Simulation software as a part of COP290 Course at IIT Delhi.
Team Members: Shreshth Tuli (2016CS10680), Sankalan Pal Chowdhury (2016CS10701)
## Aim

The package is supposed to have the following functionalities:

    We should be able to interactively add New Starlings to a Flock with variable attributes
    Given a Flock, we should be able to simulate their movement vis-a-vis various Internal
    and External Forces.
    We should also be able to calculate the instantaneous power and force on each Starling, and check if these values are in a sane         range to prove the correctness of our simulation
![Screenshot]( /screens/200_boids.PNG?raw=true "Simulation with 200 Boids")

## Structure
The package structure for the software package is as follows:
Engineering Drawing Software
|<br/>
|-> bin<br/>
|-> release<br/>
|-> doc<br/>
|-> forms<br/>
|-> include<br/>
|-> screen<br/>
|-> src<br/>
|-> lib<br/>
&nbsp;&nbsp;|-> conf<br/>
  &nbsp;&nbsp;|-> features<br/>
  &nbsp;&nbsp;|-> modules<br/>
  &nbsp;&nbsp;|-> Plugins<br/>
  &nbsp;&nbsp;|-> Win32<br/>

Following is the description of the directories:

    bin : Object files for the executable
    release : Contains the main executable 
    doc : Documentation and related files
    forms : Contains the form descriptors for UI purposes
    include : Contains all header files for the project
    screen : some screens showing different features
    src : source (C++, XML) files developed for the software
    lib : contains standard libraries of OpenGL and Qt for UI

Qt and OpenGL

The Model has been developed using Qt and OpenGL libraries. These are not required to be installed, as the executable is statically linked and deployment ready. This is not a cross-platform software and is built to run on Windows.
Compilation and execution instructions

In the top directory run:

```
make
```

(In case this does not work, statically linked executable in Release directory can be used) 
