##############################################################################
Connect 4 game - Sebastian Sardina version (ssardina@gmail.com)

This version has been produced by Sebastian Sardina in Semester 1, 2016. 

It is based on previous version, but has a few improvements, including:

- Better handling of the seed to make games truly different
- New options to change size of board
- Timing and printing of each player move
##############################################################################

Once you unzip your c4-c package you can compile it and run it right away:

$ make
$ ./c4

This will run it interactively.

You will see when you did the make that only 2 agent players have been found:

 * Found agent 'random'
 * Found agent 'simple'

Hence, when you run it you will be able to select just 3 type of
players: random, simple, or human.

You can run it with the agents specified:

$ ./c4 simple random

Options are:
		 --help:  this printout.
		 --width n: width of the board.
		 --height n:  height of the board.
		 --level n:  depth level for depth-minimax.
		 --fast disables the delay between computer moves, making the game much faster.


=======================
MEDIUM PLAYER
=======================

A medium-level player is provided in binary code that you can compile
as well. Depending on the architecture, you need to use one of the
following files:

1. agent_medium.o.sample.linux32 : 
   to be used if you run on Linux 32 bits 

2. agent_medium.o.sample.linux64 : 
   to be used if you run on Linux 64 bits

So all you need to do is rename/copy one of these files to
agent_medium.o.sample and run:

$ make clean c4

Now, you should see the following at compile time:

 * Found agent 'random'
 * Found agent 'simple'
 * Found agent 'medium'

Now, you can run ./c4 and you should also have the option of a new
player "medium". For example:

./c4 <your agent> medium






##############################################################################
EOF
##############################################################################

