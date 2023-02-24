SDL could not create thread if `avdevice_register_all()` is called.

Build:

```
meson setup x
ninja -Cx
```

Execute:

```
x/sample
```

On my machine:

```console
$ x/sample
device = 0
Couldn't create audio thread
```

If I remove the call to `avdevice_register_all()`:

```
$ x/sample
device = 2
```

See https://github.com/libsdl-org/SDL/issues/7367
