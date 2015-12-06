local M = {}

M.name = "TestPlugin"
M.pver = "1.0"
M.ptype = "background"

function M.run()
    io.write(5*2)
end

return M