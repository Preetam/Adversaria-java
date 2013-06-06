Adversaria
==========

Time-series logging that doesn't suck

Requirements
----
* Java 1.7
* ant

Usage
----
Build:

    $ make

Install convenient shell script:

    # make install

General argument format:

    $ adversaria [function] [file name] [[arguments]]

### Create

Initializes a new log file

    $ adversaria create log.db 

### Insert

Inserts a key/value pair. The first argument after the file name is an integer key -- probably a unix timestamp.
The next few arguments (at least one) are floats.

    $ adversaria insert log.db 1370233172 0.0 0.0 1.0

### Export

Exports a single key/value pair. The argument is the key.

    $ adversaria export log.db 1370233172

### Dump

Outputs all key/value pairs.

    $ adversaria export log.db

### Range

Gets a range of key/value pairs. Arguments are two keys.

    $ adversaria range log.db 1370233000 1370233172


### Size

Prints the size of the log.

    $ adversaria size log.db

License
----
MIT
