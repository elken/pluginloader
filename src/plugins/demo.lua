local M = {}

M.name = "Demo"
M.pver = "1.0"
M.ptype = "background"

function M.run()
    io.write("Hello world\n")
end

return M