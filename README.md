# UE4TestingGround
Playground to test out ideas, and break if we need to.

Developed in C++. Developers, please pull the repo and work from what we have, do NOT push a clean project unless instructed to.

ExplodingActor.cpp/h
Simple exploding actor. We use ComponentOverlapMulti to get the array of actors we're about to affect, based on the size of our sphere overlap.
We then apply a radial impact, with the origin of our exploding actor.
