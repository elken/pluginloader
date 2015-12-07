local M = {}

M.name = "Demo"
M.pver = "1.0"
M.ptype = "background"

function M.run()
	print(type(testVar),  testVar)
	print(type(testInt),  testInt)
	print(type(testBool), testBool)
end

return M