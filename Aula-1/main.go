package main 

import "fmt"


type frontboy struct {
	nome string
	framework string
	ling_fav string
}
func main(){
	manoel := frontboy{"manoel", "react", "python"}
	fmt.Println(manoel)
}
