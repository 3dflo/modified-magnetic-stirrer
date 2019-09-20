
<p align="center">
<h1 align="center">Creating a great bioreactor for everyone!</h1>
</p>

## Hello!
Welcome to the Magnetic Stirrer project repository! It started in the year 2019 as an universtity project. We work on a low cost, open source bioreactor with a volume up to 4 l. As one sub-project, a low friction stirrer with multiple replaceable stirrer geometries is developed by modifying a simple commercial magnetic stirrer. It is supposed to work as a stand-alone stirrer as well as to be controlable via web interface.

Software and hardware will be described later. If you are interested, you can read a bit more about the idea behind the project in this README.

You can directly jump to the sections:

- [How everything started](#how-everything-started)
- [A bit of background](#why-should-you-care-about-this-bioreactor)
- [What's to solve?](#let-me-present-to-you-the-problem)
- [How to build the modified magnetic stirrer](#how-to-build-the-modified-magnetic-stirrer)
- [Who is behind all this?](#who-is-behind-all-this)


## How everything started
We are a group of Master students in the field of life sciences. With the opening of the new student's Makerspace at our campus, a Makerspace-related class should be launched at the same time. A lot of steps took place in a short time and soon, a team was found to participate in the first class taking place as a pilot project. 

## Why should you care about this bioreactor?
Laboratory scaled bioreactors are part of several lab courses at university. But as most courses are only meant to be half-day events, it was not possible to observe and compare the growing of microorganisms in live until now. For that purpose, we want to develop a system, which may be controled and observed via an web interface. For providing this sytem with only low costs, the bioreactor is constructed by material available in almost every lab as well as by self-created tools, perfectly adapted for the named application. Additionally, the communication will be realized by a bus-system.

## Let me present to you: The Problem
The main reason to develop this bioreactor system is to provide to the students a possibility to observe the microorganisms' activity in real time while only beeing present at course half of the day, as described before. But why should you care about the stirrer? The stirrer is not only responsible for creating a homogenous environment concerning nutrients, waste materials, gas, fermentation products but also microorganisms. It is furthermore necessary to guarantee the delivery of oxygen out of air for aerob processes. Nevertheless, some products and cells are very sensitive to friction. As commercial magnets for magnetic stirrers are used to lay on the ground while stirring, a high friction results and might lead to significant losses in product or cell number. Additionally, adapting the stirrer geometry to the explicit system can improve the fermentation's results. Therefore, a flexible stirrer is developped, which may be driven by a commercial magnetic stirrer, but which provides a low friction stirring solution with several replaceable stirrer geometries such as disks or propellers.

## How to build the modified magnetic stirrer

Let's start to build it.

Have a look at the [Step-by-step Guide](https://github.com/3DFlo/modified-magnetic-stirrer/blob/master/Step-by-step-introduction.md).

Pictures and more informations:

First you need to have a look at the 3D comonents and if they fit your need. You probably have to modify the torque support for the servo motor [Drehmomentstütze.stl](https://github.com/3DFlo/modified-magnetic-stirrer/blob/master/Hardware/Drehmomentst%C3%BCtze.stl). 
The rest of the parts can be found under [Hardware](https://github.com/3DFlo/modified-magnetic-stirrer/tree/master/Hardware). These have to be 3D printed. The Hybrid_Stevenrohr.stl together with Scheibe.stl should be combined with a so called Stevenrohr (sterntube in english). This is the main part of the stirrer:

<img src="https://github.com/3DFlo/modified-magnetic-stirrer/blob/master/Hardware/Pictures/Stevenrohr_01.jpg" alt="drawing" width="300"/>

Now the servo motor can be combined with the torque support:

<img src="https://github.com/3DFlo/modified-magnetic-stirrer/blob/master/Hardware/Pictures/Drehmomentst%C3%BCtze.jpg" alt="drawing" width="300"/>

At last the hall sensor has to be added to the lower side of the magnetic stirrer. The sensor has to be very close to the magnets in the stirrer. Otherwise it wont work!

<img src="https://github.com/3DFlo/modified-magnetic-stirrer/blob/master/Hardware/Pictures/HallSensor.jpg" alt="drawing" width="300"/>

All parts have to be combined with the arduino uno like this:

<img src="https://github.com/3DFlo/modified-magnetic-stirrer/blob/master/Hardware/Pictures/Schaltbild.jpeg" alt="drawing" width="300"/>

The final version should look something like this:

<img src="https://github.com/3DFlo/modified-magnetic-stirrer/blob/master/Hardware/Pictures/Final.jpg" alt="drawing" width="300"/>

At last, load the software on the ardunio and test it.
Have fun!

## Who is behind all this?
We are students at the Technical University of Munich [university website](https://www.tum.de/nc/en/).
