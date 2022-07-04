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
- ``;`` semicolons
- ``>`` ``>>`` ``<`` ``<<`` redirections
- local variable
- env expansions + ``$?``
- line edition
- termcaps
- history (up/down arrows)
- move cursor (left/right arrows)
- move word by word (CTRL-left/CTRL-right)
- move to beginning/end of line (HOME/END)
- change line (CTRL-UP/CTRL-DOWN)
- copy/paste/cut from cursor position (ALT-X/ALT-C/ALT-V)

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
