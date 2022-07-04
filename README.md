# Minishell

`minishell` is a command interpreter based on ``bash``.<br>
It must implements basic functionalities of a shell like environment variable, builtins, pipes...

## Features

- ``cd``
- ``pwd``
- ``echo``
- ``export``
- ``unset``
- ``env``
- ``exit``
- ``CTRL-C``
- ``CTRL-\``
- ``CTRL-D``
- ``|`` pipes
- ``>`` ``>>`` ``<`` ``<<`` redirections
- local variable
- env expansions + ``$?``
- line edition
- termcaps
- history (up/down arrows)
- move cursor (left/right arrows)
- change line (CTRL-UP/CTRL-DOWN)

## Usage

```shell
# Compile the mandatory part
make

# Launch the shell
./minishell
```

## Authors

* [ybouali](https://github.com/ybouali)
* [tchtaibi](https://github.com/tchtaibii)
